#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([runtime], [0.1], [vinceliu@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror -Wno-extra-portability foreign])
LT_PREREQ([2.2])
LT_INIT([dlopen shared pic-only])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_SRCDIR([src/runtime.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Conditionals

## Enable ASAN
AC_ARG_ENABLE([asan],
[  --enable-asan    Turn on Address Sanitizer],
[ case "${enableval}" in
    yes) asan=true ;;
    no)  asan=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-asan]) ;;
esac],[asan=false])
AM_CONDITIONAL([ASAN], [test x$asan = xtrue])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
