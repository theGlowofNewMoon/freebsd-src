/*
 * FreeBSD install - a package for the installation and maintainance
 * of non-core utilities.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * Jeremy D. Lea.
 * 11 May 2002
 *
 * This is the version module. Based on pkg_version.pl by Bruce A. Mah.
 *
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/usr.sbin/pkg_install/version/main.c,v 1.1 2002/06/24 16:03:24 markm Exp $");

#include "lib.h"
#include "version.h"
#include <err.h>

static char Options[] = "dhl:L:s:tv";

char	*LimitChars = NULL;
char	*PreventChars = NULL;
char	*MatchName = NULL;

static void usage __P((void));

int
main(int argc, char **argv)
{
    int ch, cmp = 0;

    if (argc == 4 && !strcmp(argv[1], "-t")) {
	cmp = version_cmp(argv[2], argv[3]);
	printf(cmp > 0 ? ">\n" : (cmp < 0 ? "<\n" : "=\n"));
	exit(0);
    }
    else while ((ch = getopt(argc, argv, Options)) != -1) {
	switch(ch) {
	case 'v':
	    Verbose = TRUE;
	    break;

	case 'l':
	    LimitChars = optarg;
	    break;

	case 'L':
	    PreventChars = optarg;
	    break;

	case 's':
	    MatchName = optarg;
	    break;

	case 't':
	    errx(2, "Invalid -t usage.");
	    break;

	case 'h':
	case '?':
	default:
	    usage();
	    break;
	}
    }

    argc -= optind;
    argv += optind;

    return pkg_perform(argv);
}

static void
usage()
{
    fprintf(stderr, "%s\n%s\n",
	"usage: pkg_version [-hv] [-l limchar] [-L limchar] [-s string] index",
	"       pkg_version -t v1 v2");
    exit(1);
}
