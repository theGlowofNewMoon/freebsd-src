/*
 * Copyright (c) 1988, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 * Copyright (c) 2002 Networks Associates Technologies, Inc.
 * All rights reserved.
 *
 * Portions of this software were developed for the FreeBSD Project by
 * ThinkSec AS and NAI Labs, the Security Research Division of Network
 * Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035
 * ("CBOSS"), as part of the DARPA CHATS research program.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef lint
static const char copyright[] =
"@(#) Copyright (c) 1988, 1993, 1994\n\
	The Regents of the University of California.  All rights reserved.\n";
#endif /* not lint */

#ifndef lint
#if 0
static char sccsid[] = "@(#)su.c	8.3 (Berkeley) 4/2/94";
#endif
static const char rcsid[] =
  "$FreeBSD: src/usr.bin/su/su.c,v 1.68 2003/04/08 16:59:53 des Exp $";
#endif /* not lint */

#include <sys/param.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

#include <err.h>
#include <errno.h>
#include <grp.h>
#include <libutil.h>
#include <login_cap.h>
#include <paths.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

#include <security/pam_appl.h>
#include <security/openpam.h>

#define PAM_END() do {							\
	int local_ret;							\
	if (pamh != NULL) {						\
		local_ret = pam_setcred(pamh, PAM_DELETE_CRED);		\
		if (local_ret != PAM_SUCCESS)				\
			syslog(LOG_ERR, "pam_setcred: %s",		\
				pam_strerror(pamh, local_ret));		\
		if (asthem) {						\
			local_ret = pam_close_session(pamh, 0);		\
			if (local_ret != PAM_SUCCESS)			\
				syslog(LOG_ERR, "pam_close_session: %s",\
					pam_strerror(pamh, local_ret));	\
		}							\
		local_ret = pam_end(pamh, local_ret);			\
		if (local_ret != PAM_SUCCESS)				\
			syslog(LOG_ERR, "pam_end: %s",			\
				pam_strerror(pamh, local_ret));		\
	}								\
} while (0)


#define PAM_SET_ITEM(what, item) do {					\
	int local_ret;							\
	local_ret = pam_set_item(pamh, what, item);			\
	if (local_ret != PAM_SUCCESS) {					\
		syslog(LOG_ERR, "pam_set_item(" #what "): %s",		\
			pam_strerror(pamh, local_ret));			\
		errx(1, "pam_set_item(" #what "): %s",			\
			pam_strerror(pamh, local_ret));			\
	}								\
} while (0)

enum tristate { UNSET, YES, NO };

static pam_handle_t *pamh = NULL;
static char	**environ_pam;

static char	*ontty(void);
static int	chshell(char *);
static void	usage(void);
static int	export_pam_environment(void);
static int	ok_to_export(const char *);

extern char	**environ;

int
main(int argc, char *argv[])
{
	struct passwd	*pwd;
	struct pam_conv	conv = { openpam_ttyconv, NULL };
	enum tristate	iscsh;
	login_cap_t	*lc;
	union {
		const char	**a;
		char		* const *b;
	}		np;
	uid_t		ruid;
	pid_t		child_pid, child_pgrp, pid;
	int		asme, ch, asthem, fastlogin, prio, i, setwhat, retcode,
			statusp, setmaclabel;
	char		*username, *cleanenv, *class, shellbuf[MAXPATHLEN];
	const char	*p, *user, *shell, *mytty, **nargv;
	struct sigaction sa, sa_int, sa_quit, sa_pipe;
	int temp, fds[2];

	shell = class = cleanenv = NULL;
	asme = asthem = fastlogin = statusp = 0;
	user = "root";
	iscsh = UNSET;
	setmaclabel = 0;

	while ((ch = getopt(argc, argv, "-flmsc:")) != -1)
		switch ((char)ch) {
		case 'f':
			fastlogin = 1;
			break;
		case '-':
		case 'l':
			asme = 0;
			asthem = 1;
			break;
		case 'm':
			asme = 1;
			asthem = 0;
			break;
		case 's':
			setmaclabel = 1;
			break;
		case 'c':
			class = optarg;
			break;
		case '?':
		default:
			usage();
		}

	if (optind < argc)
		user = argv[optind++];

	if (user == NULL)
		usage();

	if (strlen(user) > MAXLOGNAME - 1)
		errx(1, "username too long");

	nargv = malloc(sizeof(char *) * (argc + 4));
	if (nargv == NULL)
		errx(1, "malloc failure");

	nargv[argc + 3] = NULL;
	for (i = argc; i >= optind; i--)
		nargv[i + 3] = argv[i];
	np.a = &nargv[i + 3];

	argv += optind;

	errno = 0;
	prio = getpriority(PRIO_PROCESS, 0);
	if (errno)
		prio = 0;

	setpriority(PRIO_PROCESS, 0, -2);
	openlog("su", LOG_CONS, LOG_AUTH);

	/* get current login name, real uid and shell */
	ruid = getuid();
	username = getlogin();
	pwd = getpwnam(username);
	if (username == NULL || pwd == NULL || pwd->pw_uid != ruid)
		pwd = getpwuid(ruid);
	if (pwd == NULL)
		errx(1, "who are you?");

	username = strdup(pwd->pw_name);
	if (username == NULL)
		err(1, "strdup failure");

	if (asme) {
		if (pwd->pw_shell != NULL && *pwd->pw_shell != '\0') {
			/* must copy - pwd memory is recycled */
			shell = strncpy(shellbuf, pwd->pw_shell,
			    sizeof(shellbuf));
			shellbuf[sizeof(shellbuf) - 1] = '\0';
		}
		else {
			shell = _PATH_BSHELL;
			iscsh = NO;
		}
	}

	/* Do the whole PAM startup thing */
	retcode = pam_start("su", user, &conv, &pamh);
	if (retcode != PAM_SUCCESS) {
		syslog(LOG_ERR, "pam_start: %s", pam_strerror(pamh, retcode));
		errx(1, "pam_start: %s", pam_strerror(pamh, retcode));
	}

	PAM_SET_ITEM(PAM_RUSER, username);

	mytty = ttyname(STDERR_FILENO);
	if (!mytty)
		mytty = "tty";
	PAM_SET_ITEM(PAM_TTY, mytty);

	retcode = pam_authenticate(pamh, 0);
	if (retcode != PAM_SUCCESS) {
#if 0
		syslog(LOG_ERR, "pam_authenticate: %s",
		    pam_strerror(pamh, retcode));
#endif
		syslog(LOG_AUTH|LOG_WARNING, "BAD SU %s to %s on %s",
		    username, user, mytty);
		errx(1, "Sorry");
	}
	retcode = pam_get_item(pamh, PAM_USER, (const void **)&p);
	if (retcode == PAM_SUCCESS)
		user = p;
	else
		syslog(LOG_ERR, "pam_get_item(PAM_USER): %s",
		    pam_strerror(pamh, retcode));

	retcode = pam_acct_mgmt(pamh, 0);
	if (retcode == PAM_NEW_AUTHTOK_REQD) {
		retcode = pam_chauthtok(pamh,
			PAM_CHANGE_EXPIRED_AUTHTOK);
		if (retcode != PAM_SUCCESS) {
			syslog(LOG_ERR, "pam_chauthtok: %s",
			    pam_strerror(pamh, retcode));
			errx(1, "Sorry");
		}
	}
	if (retcode != PAM_SUCCESS) {
		syslog(LOG_ERR, "pam_acct_mgmt: %s",
			pam_strerror(pamh, retcode));
		errx(1, "Sorry");
	}

	/* get target login information, default to root */
	pwd = getpwnam(user);
	if (pwd == NULL)
		errx(1, "unknown login: %s", user);
	if (class == NULL)
		lc = login_getpwclass(pwd);
	else {
		if (ruid != 0)
			errx(1, "only root may use -c");
		lc = login_getclass(class);
		if (lc == NULL)
			errx(1, "unknown class: %s", class);
	}

	/* if asme and non-standard target shell, must be root */
	if (asme) {
		if (ruid != 0 && !chshell(pwd->pw_shell))
			errx(1, "permission denied (shell).");
	}
	else if (pwd->pw_shell && *pwd->pw_shell) {
		shell = pwd->pw_shell;
		iscsh = UNSET;
	}
	else {
		shell = _PATH_BSHELL;
		iscsh = NO;
	}

	/* if we're forking a csh, we want to slightly muck the args */
	if (iscsh == UNSET) {
		p = strrchr(shell, '/');
		if (p)
			++p;
		else
			p = shell;
		iscsh = strcmp(p, "csh") ? (strcmp(p, "tcsh") ? NO : YES) : YES;
	}
	setpriority(PRIO_PROCESS, 0, prio);

	/* Switch to home directory */
	if (asthem) {
		if (chdir(pwd->pw_dir) < 0)
			errx(1, "no directory");
	}

	/*
	 * PAM modules might add supplementary groups in pam_setcred(), so
	 * initialize them first.
	 */
	if (setusercontext(lc, pwd, pwd->pw_uid, LOGIN_SETGROUP) < 0)
		err(1, "setusercontext");

	retcode = pam_setcred(pamh, PAM_ESTABLISH_CRED);
	if (retcode != PAM_SUCCESS) {
		syslog(LOG_ERR, "pam_setcred: %s",
		    pam_strerror(pamh, retcode));
		errx(1, "failed to establish credentials.");
	}
	if (asthem) {
		retcode = pam_open_session(pamh, 0);
		if (retcode != PAM_SUCCESS) {
			syslog(LOG_ERR, "pam_open_session: %s",
			    pam_strerror(pamh, retcode));
			errx(1, "failed to open session.");
		}
	}

	/*
	 * We must fork() before setuid() because we need to call
	 * pam_setcred(pamh, PAM_DELETE_CRED) as root.
	 */
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, &sa_int);
	sigaction(SIGQUIT, &sa, &sa_quit);
	sigaction(SIGPIPE, &sa, &sa_pipe);
	sa.sa_handler = SIG_DFL;
	sigaction(SIGTSTP, &sa, NULL);
	statusp = 1;
	if (pipe(fds) == -1) {
		err(1, "pipe");
		PAM_END();
		exit(1);
	}
	child_pid = fork();
	switch (child_pid) {
	default:
		close(fds[0]);
		setpgid(child_pid, child_pid);
		tcsetpgrp(1, child_pid);
		close(fds[1]);
		sigaction(SIGPIPE, &sa_pipe, NULL);
		while ((pid = waitpid(child_pid, &statusp, WUNTRACED)) != -1) {
			if (WIFSTOPPED(statusp)) {
				kill(getpid(), SIGSTOP);
				child_pgrp = getpgid(child_pid);
				tcsetpgrp(1, child_pgrp);
				kill(child_pid, SIGCONT);
				statusp = 1;
				continue;
			}
			break;
		}
		if (pid == -1)
			err(1, "waitpid");
		PAM_END();
		exit(statusp);
	case -1:
		err(1, "fork");
		PAM_END();
		exit(1);
	case 0:
		close(fds[1]);
		read(fds[0], &temp, 1);
		close(fds[0]);
		sigaction(SIGPIPE, &sa_pipe, NULL);
		sigaction(SIGINT, &sa_int, NULL);
		sigaction(SIGQUIT, &sa_quit, NULL);

		/*
		 * Set all user context except for: Environmental variables
		 * Umask Login records (wtmp, etc) Path
		 */
		setwhat = LOGIN_SETALL & ~(LOGIN_SETENV | LOGIN_SETUMASK |
			   LOGIN_SETLOGIN | LOGIN_SETPATH | LOGIN_SETGROUP |
			   LOGIN_SETMAC);
		/*
		 * If -s is present, also set the MAC label.
		 */
		if (setmaclabel)
			setwhat |= LOGIN_SETMAC;
		/*
		 * Don't touch resource/priority settings if -m has been used
		 * or -l and -c hasn't, and we're not su'ing to root.
		 */
		if ((asme || (!asthem && class == NULL)) && pwd->pw_uid)
			setwhat &= ~(LOGIN_SETPRIORITY | LOGIN_SETRESOURCES);
		if (setusercontext(lc, pwd, pwd->pw_uid, setwhat) < 0)
			err(1, "setusercontext");

		if (!asme) {
			if (asthem) {
				p = getenv("TERM");
				environ = &cleanenv;
			}

			if (asthem || pwd->pw_uid)
				setenv("USER", pwd->pw_name, 1);
			setenv("HOME", pwd->pw_dir, 1);
			setenv("SHELL", shell, 1);

			if (asthem) {
				/*
				 * Add any environmental variables that the
				 * PAM modules may have set.
				 */
				environ_pam = pam_getenvlist(pamh);
				if (environ_pam)
					export_pam_environment();

				/* set the su'd user's environment & umask */
				setusercontext(lc, pwd, pwd->pw_uid,
					LOGIN_SETPATH | LOGIN_SETUMASK |
					LOGIN_SETENV);
				if (p)
					setenv("TERM", p, 1);
			}
		}
		login_close(lc);

		if (iscsh == YES) {
			if (fastlogin)
				*np.a-- = "-f";
			if (asme)
				*np.a-- = "-m";
		}
		/* csh strips the first character... */
		*np.a = asthem ? "-su" : iscsh == YES ? "_su" : "su";

		if (ruid != 0)
			syslog(LOG_NOTICE, "%s to %s%s", username, user,
			    ontty());

		execv(shell, np.b);
		err(1, "%s", shell);
	}
}

static int
export_pam_environment(void)
{
	char	**pp;

	for (pp = environ_pam; *pp != NULL; pp++) {
		if (ok_to_export(*pp))
			putenv(*pp);
		free(*pp);
	}
	return PAM_SUCCESS;
}

/*
 * Sanity checks on PAM environmental variables:
 * - Make sure there is an '=' in the string.
 * - Make sure the string doesn't run on too long.
 * - Do not export certain variables.  This list was taken from the
 *   Solaris pam_putenv(3) man page.
 * Note that if the user is chrooted, PAM may have a better idea than we
 * do of where her home directory is.
 */
static int
ok_to_export(const char *s)
{
	static const char *noexport[] = {
		"SHELL", /* "HOME", */ "LOGNAME", "MAIL", "CDPATH",
		"IFS", "PATH", NULL
	};
	const char **pp;
	size_t n;

	if (strlen(s) > 1024 || strchr(s, '=') == NULL)
		return 0;
	if (strncmp(s, "LD_", 3) == 0)
		return 0;
	for (pp = noexport; *pp != NULL; pp++) {
		n = strlen(*pp);
		if (s[n] == '=' && strncmp(s, *pp, n) == 0)
			return 0;
	}
	return 1;
}

static void
usage(void)
{

	fprintf(stderr, "usage: su [-] [-flms] [-c class] [login [args]]\n");
	exit(1);
}

static int
chshell(char *sh)
{
	int r;
	char *cp;

	r = 0;
	setusershell();
	do {
		cp = getusershell();
		r = strcmp(cp, sh);
	} while (!r && cp != NULL);
	endusershell();
	return r;
}

static char *
ontty(void)
{
	char *p;
	static char buf[MAXPATHLEN + 4];

	buf[0] = 0;
	p = ttyname(STDERR_FILENO);
	if (p)
		snprintf(buf, sizeof(buf), " on %s", p);
	return buf;
}
