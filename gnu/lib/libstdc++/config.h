/* $FreeBSD: src/gnu/lib/libstdc++/config.h,v 1.6 2003/04/29 18:10:45 kan Exp $ */

/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define if you have a working `mmap' system call.  */
#define HAVE_MMAP 1

// Define if GCC supports weak symbols.
#define _GLIBCPP_SUPPORTS_WEAK __GXX_WEAK__

// Include I/O support for 'long long' and 'unsigned long long'.
#define _GLIBCPP_USE_LONG_LONG 1

// Define if C99 features such as lldiv_t, llabs, lldiv should be exposed.
#define _GLIBCPP_USE_C99 1

// Define if code specialized for wchar_t should be used.
#define _GLIBCPP_USE_WCHAR_T 1

// Define if using setrlimit to limit memory usage during 'make check'.
/* #undef _GLIBCPP_MEM_LIMITS */

// Define to use concept checking code from the boost libraries.
/* #undef _GLIBCPP_CONCEPT_CHECKS */

// Define to use symbol versioning in the shared library.
/* #undef _GLIBCPP_SYMVER */

// Define symbol versioning in assember directives. If symbol
// versioning is beigng used, and the assembler supports this kind of
// thing, then use it.
// NB: _GLIBCPP_AT_AT is a hack to work around quoting issues in m4.
#if _GLIBCPP_SYMVER
  #define _GLIBCPP_ASM_SYMVER(cur, old, version) \
   asm (".symver " #cur "," #old _GLIBCPP_AT_AT #version);
#else
  #define _GLIBCPP_ASM_SYMVER(cur, old, version)
#endif

// Define if gthr-default.h exists (meaning that threading support is enabled).
#define HAVE_GTHR_DEFAULT 1

// Define if mbstate_t exists in wchar.h.
#define HAVE_MBSTATE_T 1

// Define if you have the modff function.
#define HAVE_MODFF 1

// Define if you have the modfl function.
/* #undef HAVE_MODFL */

// Define if you have the expf function.
#define HAVE_EXPF 1

// Define if you have the expl function.
/* #undef HAVE_EXPL */

// Define if you have the hypotf function.
#define HAVE_HYPOTF 1

// Define if you have the hypotl function.
/* #undef HAVE_HYPOTL */

// Define if the compiler/host combination has __builtin_abs
#define HAVE___BUILTIN_ABS 1

// Define if the compiler/host combination has __builtin_labs
#define HAVE___BUILTIN_LABS 1

// Define if the compiler/host combination has __builtin_cos
/* #undef HAVE___BUILTIN_COS */

// Define if the compiler/host combination has __builtin_cosf
/* #undef HAVE___BUILTIN_COSF */

// Define if the compiler/host combination has __builtin_cosl
/* #undef HAVE___BUILTIN_COSL */

// Define if the compiler/host combination has __builtin_fabs
#define HAVE___BUILTIN_FABS 1

// Define if the compiler/host combination has __builtin_fabsf
#define HAVE___BUILTIN_FABSF 1

// Define if the compiler/host combination has __builtin_fabsl
#define HAVE___BUILTIN_FABSL 1

// Define if the compiler/host combination has __builtin_sin
/* #undef HAVE___BUILTIN_SIN */

// Define if the compiler/host combination has __builtin_sinf
/* #undef HAVE___BUILTIN_SINF */

// Define if the compiler/host combination has __builtin_sinl
/* #undef HAVE___BUILTIN_SINL */

// Define if the compiler/host combination has __builtin_sqrt
/* #undef HAVE___BUILTIN_SQRT */

// Define if the compiler/host combination has __builtin_sqrtf
/* #undef HAVE___BUILTIN_SQRTF */

// Define if the compiler/host combination has __builtin_sqrtl
/* #undef HAVE___BUILTIN_SQRTL */

// Define if LC_MESSAGES is available in <locale.h>.
#define HAVE_LC_MESSAGES 1

/* Define if you have the __signbit function.  */
#define HAVE___SIGNBIT 1

/* Define if you have the __signbitf function.  */
/* #undef HAVE___SIGNBITF */

/* Define if you have the __signbitl function.  */
/* #undef HAVE___SIGNBITL */

/* Define if you have the _acosf function.  */
/* #undef HAVE__ACOSF */

/* Define if you have the _acosl function.  */
/* #undef HAVE__ACOSL */

/* Define if you have the _asinf function.  */
/* #undef HAVE__ASINF */

/* Define if you have the _asinl function.  */
/* #undef HAVE__ASINL */

/* Define if you have the _atan2f function.  */
/* #undef HAVE__ATAN2F */

/* Define if you have the _atan2l function.  */
/* #undef HAVE__ATAN2L */

/* Define if you have the _atanf function.  */
/* #undef HAVE__ATANF */

/* Define if you have the _atanl function.  */
/* #undef HAVE__ATANL */

/* Define if you have the _ceilf function.  */
/* #undef HAVE__CEILF */

/* Define if you have the _ceill function.  */
/* #undef HAVE__CEILL */

/* Define if you have the _copysign function.  */
/* #undef HAVE__COPYSIGN */

/* Define if you have the _copysignl function.  */
/* #undef HAVE__COPYSIGNL */

/* Define if you have the _cosf function.  */
/* #undef HAVE__COSF */

/* Define if you have the _coshf function.  */
/* #undef HAVE__COSHF */

/* Define if you have the _coshl function.  */
/* #undef HAVE__COSHL */

/* Define if you have the _cosl function.  */
/* #undef HAVE__COSL */

/* Define if you have the _expf function.  */
/* #undef HAVE__EXPF */

/* Define if you have the _expl function.  */
/* #undef HAVE__EXPL */

/* Define if you have the _fabsf function.  */
/* #undef HAVE__FABSF */

/* Define if you have the _fabsl function.  */
/* #undef HAVE__FABSL */

/* Define if you have the _finite function.  */
/* #undef HAVE__FINITE */

/* Define if you have the _finitef function.  */
/* #undef HAVE__FINITEF */

/* Define if you have the _finitel function.  */
/* #undef HAVE__FINITEL */

/* Define if you have the _floorf function.  */
/* #undef HAVE__FLOORF */

/* Define if you have the _floorl function.  */
/* #undef HAVE__FLOORL */

/* Define if you have the _fmodf function.  */
/* #undef HAVE__FMODF */

/* Define if you have the _fmodl function.  */
/* #undef HAVE__FMODL */

/* Define if you have the _fpclass function.  */
/* #undef HAVE__FPCLASS */

/* Define if you have the _frexpf function.  */
/* #undef HAVE__FREXPF */

/* Define if you have the _frexpl function.  */
/* #undef HAVE__FREXPL */

/* Define if you have the _hypot function.  */
/* #undef HAVE__HYPOT */

/* Define if you have the _hypotf function.  */
/* #undef HAVE__HYPOTF */

/* Define if you have the _hypotl function.  */
/* #undef HAVE__HYPOTL */

/* Define if you have the _isinf function.  */
/* #undef HAVE__ISINF */

/* Define if you have the _isinff function.  */
/* #undef HAVE__ISINFF */

/* Define if you have the _isinfl function.  */
/* #undef HAVE__ISINFL */

/* Define if you have the _isnan function.  */
/* #undef HAVE__ISNAN */

/* Define if you have the _isnanf function.  */
/* #undef HAVE__ISNANF */

/* Define if you have the _isnanl function.  */
/* #undef HAVE__ISNANL */

/* Define if you have the _ldexpf function.  */
/* #undef HAVE__LDEXPF */

/* Define if you have the _ldexpl function.  */
/* #undef HAVE__LDEXPL */

/* Define if you have the _log10f function.  */
/* #undef HAVE__LOG10F */

/* Define if you have the _log10l function.  */
/* #undef HAVE__LOG10L */

/* Define if you have the _logf function.  */
/* #undef HAVE__LOGF */

/* Define if you have the _logl function.  */
/* #undef HAVE__LOGL */

/* Define if you have the _modff function.  */
/* #undef HAVE__MODFF */

/* Define if you have the _modfl function.  */
/* #undef HAVE__MODFL */

/* Define if you have the _powf function.  */
/* #undef HAVE__POWF */

/* Define if you have the _powl function.  */
/* #undef HAVE__POWL */

/* Define if you have the _qfpclass function.  */
/* #undef HAVE__QFPCLASS */

/* Define if you have the _sincos function.  */
/* #undef HAVE__SINCOS */

/* Define if you have the _sincosf function.  */
/* #undef HAVE__SINCOSF */

/* Define if you have the _sincosl function.  */
/* #undef HAVE__SINCOSL */

/* Define if you have the _sinf function.  */
/* #undef HAVE__SINF */

/* Define if you have the _sinhf function.  */
/* #undef HAVE__SINHF */

/* Define if you have the _sinhl function.  */
/* #undef HAVE__SINHL */

/* Define if you have the _sinl function.  */
/* #undef HAVE__SINL */

/* Define if you have the _sqrtf function.  */
/* #undef HAVE__SQRTF */

/* Define if you have the _sqrtl function.  */
/* #undef HAVE__SQRTL */

/* Define if you have the _tanf function.  */
/* #undef HAVE__TANF */

/* Define if you have the _tanhf function.  */
/* #undef HAVE__TANHF */

/* Define if you have the _tanhl function.  */
/* #undef HAVE__TANHL */

/* Define if you have the _tanl function.  */
/* #undef HAVE__TANL */

/* Define if you have the acosf function.  */
#define HAVE_ACOSF 1

/* Define if you have the acosl function.  */
/* #undef HAVE_ACOSL */

/* Define if you have the asinf function.  */
#define HAVE_ASINF 1

/* Define if you have the asinl function.  */
/* #undef HAVE_ASINL */

/* Define if you have the atan2f function.  */
#define HAVE_ATAN2F 1

/* Define if you have the atan2l function.  */
/* #undef HAVE_ATAN2L */

/* Define if you have the atanf function.  */
#define HAVE_ATANF 1

/* Define if you have the atanl function.  */
/* #undef HAVE_ATANL */

/* Define if you have the btowc function.  */
#define HAVE_BTOWC 1

/* Define if you have the ceilf function.  */
#define HAVE_CEILF 1

/* Define if you have the ceill function.  */
/* #undef HAVE_CEILL */

/* Define if you have the copysign function.  */
#define HAVE_COPYSIGN 1

/* Define if you have the copysignf function.  */
#define HAVE_COPYSIGNF 1

/* Define if you have the copysignl function.  */
/* #undef HAVE_COPYSIGNL */

/* Define if you have the cosf function.  */
#define HAVE_COSF 1

/* Define if you have the coshf function.  */
#define HAVE_COSHF 1

/* Define if you have the coshl function.  */
/* #undef HAVE_COSHL */

/* Define if you have the cosl function.  */
/* #undef HAVE_COSL */

/* Define if you have the drand48 function.  */
#define HAVE_DRAND48 1

/* Define if you have the expf function.  */
#define HAVE_EXPF 1

/* Define if you have the expl function.  */
/* #undef HAVE_EXPL */

/* Define if you have the fabsf function.  */
#define HAVE_FABSF 1

/* Define if you have the fabsl function.  */
/* #undef HAVE_FABSL */

/* Define if you have the fgetwc function.  */
#define HAVE_FGETWC 1

/* Define if you have the fgetws function.  */
#define HAVE_FGETWS 1

/* Define if you have the finite function.  */
#define HAVE_FINITE 1

/* Define if you have the finitef function.  */
#define HAVE_FINITEF 1

/* Define if you have the finitel function.  */
/* #undef HAVE_FINITEL */

/* Define if you have the floorf function.  */
#define HAVE_FLOORF 1

/* Define if you have the floorl function.  */
/* #undef HAVE_FLOORL */

/* Define if you have the fmodf function.  */
#define HAVE_FMODF 1

/* Define if you have the fmodl function.  */
/* #undef HAVE_FMODL */

/* Define if you have the fpclass function.  */
/* #undef HAVE_FPCLASS */

/* Define if you have the fputwc function.  */
#define HAVE_FPUTWC 1

/* Define if you have the fputws function.  */
#define HAVE_FPUTWS 1

/* Define if you have the frexpf function.  */
#define HAVE_FREXPF 1

/* Define if you have the frexpl function.  */
/* #undef HAVE_FREXPL */

/* Define if you have the fwide function.  */
#define HAVE_FWIDE 1

/* Define if you have the fwprintf function.  */
#define HAVE_FWPRINTF 1

/* Define if you have the fwscanf function.  */
#define HAVE_FWSCANF 1

/* Define if you have the getpagesize function.  */
#define HAVE_GETPAGESIZE 1

/* Define if you have the getwc function.  */
#define HAVE_GETWC 1

/* Define if you have the getwchar function.  */
#define HAVE_GETWCHAR 1

/* Define if you have the hypot function.  */
#define HAVE_HYPOT 1

/* Define if you have the hypotf function.  */
#define HAVE_HYPOTF 1

/* Define if you have the hypotl function.  */
/* #undef HAVE_HYPOTL */

/* Define if you have the iconv function.  */
/* #undef HAVE_ICONV */

/* Define if you have the iconv_close function.  */
/* #undef HAVE_ICONV_CLOSE */

/* Define if you have the iconv_open function.  */
/* #undef HAVE_ICONV_OPEN */

/* Define if you have the isatty function.  */
#define HAVE_ISATTY 1

/* Define if you have the isinf function.  */
#define HAVE_ISINF 1

/* Define if you have the isinff function.  */
/* #undef HAVE_ISINFF */

/* Define if you have the isinfl function.  */
/* #undef HAVE_ISINFL */

/* Define if you have the isnan function.  */
#define HAVE_ISNAN 1

/* Define if you have the isnanf function.  */
#define HAVE_ISNANF 1

/* Define if you have the isnanl function.  */
/* #undef HAVE_ISNANL */

/* Define if you have the ldexpf function.  */
#define HAVE_LDEXPF 1

/* Define if you have the ldexpl function.  */
/* #undef HAVE_LDEXPL */

/* Define if you have the log10f function.  */
#define HAVE_LOG10F 1

/* Define if you have the log10l function.  */
/* #undef HAVE_LOG10L */

/* Define if you have the logf function.  */
#define HAVE_LOGF 1

/* Define if you have the logl function.  */
/* #undef HAVE_LOGL */

/* Define if you have the mbrlen function.  */
#define HAVE_MBRLEN 1

/* Define if you have the mbrtowc function.  */
#define HAVE_MBRTOWC 1

/* Define if you have the mbsinit function.  */
#define HAVE_MBSINIT 1

/* Define if you have the mbsrtowcs function.  */
#define HAVE_MBSRTOWCS 1

/* Define if you have the modff function.  */
#define HAVE_MODFF 1

/* Define if you have the modfl function.  */
/* #undef HAVE_MODFL */

/* Define if you have the nan function.  */
/* #undef HAVE_NAN */

/* Define if you have the nl_langinfo function.  */
#define HAVE_NL_LANGINFO 1

/* Define if you have the powf function.  */
#define HAVE_POWF 1

/* Define if you have the powl function.  */
/* #undef HAVE_POWL */

/* Define if you have the putwc function.  */
#define HAVE_PUTWC 1

/* Define if you have the putwchar function.  */
#define HAVE_PUTWCHAR 1

/* Define if you have the qfpclass function.  */
/* #undef HAVE_QFPCLASS */

/* Define if you have the setenv function.  */
#define HAVE_SETENV 1

/* Define if you have the sincos function.  */
/* #undef HAVE_SINCOS */

/* Define if you have the sincosf function.  */
/* #undef HAVE_SINCOSF */

/* Define if you have the sincosl function.  */
/* #undef HAVE_SINCOSL */

/* Define if you have the sinf function.  */
#define HAVE_SINF 1

/* Define if you have the sinhf function.  */
#define HAVE_SINHF 1

/* Define if you have the sinhl function.  */
/* #undef HAVE_SINHL */

/* Define if you have the sinl function.  */
/* #undef HAVE_SINL */

/* Define if you have the sqrtf function.  */
#define HAVE_SQRTF 1

/* Define if you have the sqrtl function.  */
/* #undef HAVE_SQRTL */

/* Define if you have the strtof function.  */
#define HAVE_STRTOF 1

/* Define if you have the strtold function.  */
#define HAVE_STRTOLD 1

/* Define if you have the swprintf function.  */
#define HAVE_SWPRINTF 1

/* Define if you have the swscanf function.  */
#define HAVE_SWSCANF 1

/* Define if you have the tanf function.  */
#define HAVE_TANF 1

/* Define if you have the tanhf function.  */
#define HAVE_TANHF 1

/* Define if you have the tanhl function.  */
/* #undef HAVE_TANHL */

/* Define if you have the tanl function.  */
/* #undef HAVE_TANL */

/* Define if you have the ungetwc function.  */
#define HAVE_UNGETWC 1

/* Define if you have the vfwprintf function.  */
#define HAVE_VFWPRINTF 1

/* Define if you have the vfwscanf function.  */
#define HAVE_VFWSCANF 1

/* Define if you have the vswprintf function.  */
#define HAVE_VSWPRINTF 1

/* Define if you have the vswscanf function.  */
#define HAVE_VSWSCANF 1

/* Define if you have the vwprintf function.  */
#define HAVE_VWPRINTF 1

/* Define if you have the vwscanf function.  */
#define HAVE_VWSCANF 1

/* Define if you have the wcrtomb function.  */
#define HAVE_WCRTOMB 1

/* Define if you have the wcscat function.  */
#define HAVE_WCSCAT 1

/* Define if you have the wcschr function.  */
#define HAVE_WCSCHR 1

/* Define if you have the wcscmp function.  */
#define HAVE_WCSCMP 1

/* Define if you have the wcscoll function.  */
#define HAVE_WCSCOLL 1

/* Define if you have the wcscpy function.  */
#define HAVE_WCSCPY 1

/* Define if you have the wcscspn function.  */
#define HAVE_WCSCSPN 1

/* Define if you have the wcsftime function.  */
#define HAVE_WCSFTIME 1

/* Define if you have the wcslen function.  */
#define HAVE_WCSLEN 1

/* Define if you have the wcsncat function.  */
#define HAVE_WCSNCAT 1

/* Define if you have the wcsncmp function.  */
#define HAVE_WCSNCMP 1

/* Define if you have the wcsncpy function.  */
#define HAVE_WCSNCPY 1

/* Define if you have the wcspbrk function.  */
#define HAVE_WCSPBRK 1

/* Define if you have the wcsrchr function.  */
#define HAVE_WCSRCHR 1

/* Define if you have the wcsrtombs function.  */
#define HAVE_WCSRTOMBS 1

/* Define if you have the wcsspn function.  */
#define HAVE_WCSSPN 1

/* Define if you have the wcsstr function.  */
#define HAVE_WCSSTR 1

/* Define if you have the wcstod function.  */
#define HAVE_WCSTOD 1

/* Define if you have the wcstof function.  */
#define HAVE_WCSTOF 1

/* Define if you have the wcstok function.  */
#define HAVE_WCSTOK 1

/* Define if you have the wcstol function.  */
#define HAVE_WCSTOL 1

/* Define if you have the wcstoul function.  */
#define HAVE_WCSTOUL 1

/* Define if you have the wcsxfrm function.  */
#define HAVE_WCSXFRM 1

/* Define if you have the wctob function.  */
#define HAVE_WCTOB 1

/* Define if you have the wmemchr function.  */
#define HAVE_WMEMCHR 1

/* Define if you have the wmemcmp function.  */
#define HAVE_WMEMCMP 1

/* Define if you have the wmemcpy function.  */
#define HAVE_WMEMCPY 1

/* Define if you have the wmemmove function.  */
#define HAVE_WMEMMOVE 1

/* Define if you have the wmemset function.  */
#define HAVE_WMEMSET 1

/* Define if you have the wprintf function.  */
#define HAVE_WPRINTF 1

/* Define if you have the wscanf function.  */
#define HAVE_WSCANF 1

/* Define if you have the <endian.h> header file.  */
/* #undef HAVE_ENDIAN_H */

/* Define if you have the <float.h> header file.  */
#define HAVE_FLOAT_H 1

/* Define if you have the <fp.h> header file.  */
/* #undef HAVE_FP_H */

/* Define if you have the <gconv.h> header file.  */
/* #undef HAVE_GCONV_H */

/* Define if you have the <ieeefp.h> header file.  */
#define HAVE_IEEEFP_H 1

/* Define if you have the <inttypes.h> header file.  */
#define HAVE_INTTYPES_H 1

/* Define if you have the <locale.h> header file.  */
#define HAVE_LOCALE_H 1

/* Define if you have the <machine/endian.h> header file.  */
#define HAVE_MACHINE_ENDIAN_H 1

/* Define if you have the <machine/param.h> header file.  */
#define HAVE_MACHINE_PARAM_H 1

/* Define if you have the <nan.h> header file.  */
/* #undef HAVE_NAN_H */

/* Define if you have the <stdlib.h> header file.  */
#define HAVE_STDLIB_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <sys/isa_defs.h> header file.  */
/* #undef HAVE_SYS_ISA_DEFS_H */

/* Define if you have the <sys/machine.h> header file.  */
/* #undef HAVE_SYS_MACHINE_H */

/* Define if you have the <sys/resource.h> header file.  */
#define HAVE_SYS_RESOURCE_H 1

/* Define if you have the <sys/stat.h> header file.  */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/types.h> header file.  */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <wchar.h> header file.  */
#define HAVE_WCHAR_H 1

/* Define if you have the <wctype.h> header file.  */
#define HAVE_WCTYPE_H 1

/* Define if you have the m library (-lm).  */
#define HAVE_LIBM 1

/* Name of package */
#define PACKAGE "libstdc++"

/* Version number of package */
#define VERSION "3.2.2"

/* Define if the compiler is configured for setjmp/longjmp exceptions. */
/* #undef _GLIBCPP_SJLJ_EXCEPTIONS */

/* Define if sigsetjmp is available.   */
#define HAVE_SIGSETJMP 1

/* Only used in build directory testsuite_hooks.h. */
#define HAVE_MEMLIMIT_DATA 0

/* Only used in build directory testsuite_hooks.h. */
#define HAVE_MEMLIMIT_RSS 0

/* Only used in build directory testsuite_hooks.h. */
#define HAVE_MEMLIMIT_VMEM 0

/* Only used in build directory testsuite_hooks.h. */
#define HAVE_MEMLIMIT_AS 0

//
// Systems that have certain non-standard functions prefixed with an
// underscore, we'll handle those here. Must come after config.h.in.
//
#if defined (HAVE__ISNAN) && ! defined (HAVE_ISNAN)
# define HAVE_ISNAN 1
# define isnan _isnan
#endif

#if defined (HAVE__ISNANF) && ! defined (HAVE_ISNANF)
# define HAVE_ISNANF 1
# define isnanf _isnanf
#endif

#if defined (HAVE__ISNANL) && ! defined (HAVE_ISNANL)
# define HAVE_ISNANL 1
# define isnanl _isnanl
#endif

#if defined (HAVE__ISINF) && ! defined (HAVE_ISINF)
# define HAVE_ISINF 1
# define isinf _isinf
#endif

#if defined (HAVE__ISINFF) && ! defined (HAVE_ISINFF)
# define HAVE_ISINFF 1
# define isinff _isinff
#endif

#if defined (HAVE__ISINFL) && ! defined (HAVE_ISINFL)
# define HAVE_ISINFL 1
# define isinfl _isinfl
#endif

#if defined (HAVE__COPYSIGN) && ! defined (HAVE_COPYSIGN)
# define HAVE_COPYSIGN 1
# define copysign _copysign
#endif

#if defined (HAVE__COPYSIGNL) && ! defined (HAVE_COPYSIGNL)
# define HAVE_COPYSIGNL 1
# define copysignl _copysignl
#endif

#if defined (HAVE__COSF) && ! defined (HAVE_COSF)
# define HAVE_COSF 1
# define cosf _cosf
#endif

#if defined (HAVE__ACOSF) && ! defined (HAVE_ACOSF)
# define HAVE_ACOSF 1
# define acosf _acosf
#endif

#if defined (HAVE__ACOSL) && ! defined (HAVE_ACOSL)
# define HAVE_ACOSL 1
# define acosl _acosl
#endif

#if defined (HAVE__ASINF) && ! defined (HAVE_ASINF)
# define HAVE_ASINF 1
# define asinf _asinf
#endif

#if defined (HAVE__ASINL) && ! defined (HAVE_ASINL)
# define HAVE_ASINL 1
# define asinl _asinl
#endif

#if defined (HAVE__ATANF) && ! defined (HAVE_ATANF)
# define HAVE_ATANF 1
# define atanf _atanf
#endif

#if defined (HAVE__ATANL) && ! defined (HAVE_ATANL)
# define HAVE_ATANL 1
# define atanl _atanl
#endif

#if defined (HAVE__CEILF) && ! defined (HAVE_CEILF)
# define HAVE_CEILF 1
# define aceil _ceilf
#endif

#if defined (HAVE__CEILL) && ! defined (HAVE_CEILL)
# define HAVE_CEILL 1
# define aceil _ceill
#endif

#if defined (HAVE__COSHF) && ! defined (HAVE_COSHF)
# define HAVE_COSHF 1
# define coshf _coshf
#endif

#if defined (HAVE__COSL) && ! defined (HAVE_COSL)
# define HAVE_COSL 1
# define cosl _cosl
#endif

#if defined (HAVE__LOGF) && ! defined (HAVE_LOGF)
# define HAVE_LOGF 1
# define logf _logf
#endif

#if defined (HAVE__COSHL) && ! defined (HAVE_COSHL)
# define HAVE_COSHL 1
# define coshl _coshl
#endif

#if defined (HAVE__EXPF) && ! defined (HAVE_EXPF)
# define HAVE_EXPF 1
# define expf _expf
#endif

#if defined (HAVE__EXPL) && ! defined (HAVE_EXPL)
# define HAVE_EXPL 1
# define expl _expl
#endif

#if defined (HAVE__FABSF) && ! defined (HAVE_FABSF)
# define HAVE_FABSF 1
# define fabsf _fabsf
#endif

#if defined (HAVE__FABSL) && ! defined (HAVE_FABSL)
# define HAVE_FABSL 1
# define fabsl _fabsl
#endif

#if defined (HAVE__FLOORF) && ! defined (HAVE_FLOORF)
# define HAVE_FLOORF 1
# define floorf _floorf
#endif

#if defined (HAVE__FLOORL) && ! defined (HAVE_FLOORL)
# define HAVE_FLOORL 1
# define floorl _floorl
#endif

#if defined (HAVE__FMODF) && ! defined (HAVE_FMODF)
# define HAVE_FMODF 1
# define fmodf _fmodf
#endif

#if defined (HAVE__FMODL) && ! defined (HAVE_FMODL)
# define HAVE_FMODL 1
# define fmodl _fmodl
#endif

#if defined (HAVE__FREXPF) && ! defined (HAVE_FREXPF)
# define HAVE_FREXPF 1
# define frexpf _frexpf
#endif

#if defined (HAVE__FREXPL) && ! defined (HAVE_FREXPL)
# define HAVE_FREXPL 1
# define frexpl _frexpl
#endif

#if defined (HAVE__LDEXPF) && ! defined (HAVE_LDEXPF)
# define HAVE_LDEXPF 1
# define ldexpf _ldexpf
#endif

#if defined (HAVE__LDEXPL) && ! defined (HAVE_LDEXPL)
# define HAVE_LDEXPL 1
# define ldexpl _ldexpl
#endif

#if defined (HAVE__LOG10F) && ! defined (HAVE_LOG10F)
# define HAVE_LOG10F 1
# define log10f _log10f
#endif

#if defined (HAVE__LOGL) && ! defined (HAVE_LOGL)
# define HAVE_LOGL 1
# define logl _logl
#endif

#if defined (HAVE__POWF) && ! defined (HAVE_POWF)
# define HAVE_POWF 1
# define powf _powf
#endif

#if defined (HAVE__LOG10L) && ! defined (HAVE_LOG10L)
# define HAVE_LOG10L 1
# define log10l _log10l
#endif

#if defined (HAVE__MODF) && ! defined (HAVE_MODF)
# define HAVE_MODF 1
# define modf _modf
#endif

#if defined (HAVE__MODL) && ! defined (HAVE_MODL)
# define HAVE_MODL 1
# define modl _modl
#endif

#if defined (HAVE__SINF) && ! defined (HAVE_SINF)
# define HAVE_SINF 1
# define sinf _sinf
#endif

#if defined (HAVE__POWL) && ! defined (HAVE_POWL)
# define HAVE_POWL 1
# define powl _powl
#endif

#if defined (HAVE__SINHF) && ! defined (HAVE_SINHF)
# define HAVE_SINHF 1
# define sinhf _sinhf
#endif

#if defined (HAVE__SINL) && ! defined (HAVE_SINL)
# define HAVE_SINL 1
# define sinl _sinl
#endif

#if defined (HAVE__SQRTF) && ! defined (HAVE_SQRTF)
# define HAVE_SQRTF 1
# define sqrtf _sqrtf
#endif

#if defined (HAVE__SINHL) && ! defined (HAVE_SINHL)
# define HAVE_SINHL 1
# define sinhl _sinhl
#endif

#if defined (HAVE__TANF) && ! defined (HAVE_TANF)
# define HAVE_TANF 1
# define tanf _tanf
#endif

#if defined (HAVE__SQRTL) && ! defined (HAVE_SQRTL)
# define HAVE_SQRTL 1
# define sqrtl _sqrtl
#endif

#if defined (HAVE__TANHF) && ! defined (HAVE_TANHF)
# define HAVE_TANHF 1
# define tanhf _tanhf
#endif

#if defined (HAVE__TANL) && ! defined (HAVE_TANL)
# define HAVE_TANF 1
# define tanf _tanf
#endif

#if defined (HAVE__STRTOF) && ! defined (HAVE_STRTOF)
# define HAVE_STRTOF 1
# define strtof _strtof
#endif

#if defined (HAVE__TANHL) && ! defined (HAVE_TANHL)
# define HAVE_TANHL 1
# define tanhl _tanhl
#endif

#if defined (HAVE__STRTOLD) && ! defined (HAVE_STRTOLD)
# define HAVE_STRTOLD 1
# define strtold _strtold
#endif

#if defined (HAVE__SINCOS) && ! defined (HAVE_SINCOS)
# define HAVE_SINCOS 1
# define sincos _sincos
#endif

#if defined (HAVE__SINCOSF) && ! defined (HAVE_SINCOSF)
# define HAVE_SINCOSF 1
# define sincosf _sincosf
#endif

#if defined (HAVE__SINCOSL) && ! defined (HAVE_SINCOSL)
# define HAVE_SINCOSL 1
# define sincosl _sincosl
#endif

#if defined (HAVE__FINITE) && ! defined (HAVE_FINITE)
# define HAVE_FINITE 1
# define finite _finite
#endif

#if defined (HAVE__FINITEF) && ! defined (HAVE_FINITEF)
# define HAVE_FINITEF 1
# define finitef _finitef
#endif

#if defined (HAVE__FINITEL) && ! defined (HAVE_FINITEL)
# define HAVE_FINITEL 1
# define finitel _finitel
#endif

#if defined (HAVE__QFINITE) && ! defined (HAVE_QFINITE)
# define HAVE_QFINITE 1
# define qfinite _qfinite
#endif

#if defined (HAVE__FPCLASS) && ! defined (HAVE_FPCLASS)
# define HAVE_FPCLASS 1
# define fpclass _fpclass
#endif

#if defined (HAVE__QFPCLASS) && ! defined (HAVE_QFPCLASS)
# define HAVE_QFPCLASS 1
# define qfpclass _qfpclass
#endif

