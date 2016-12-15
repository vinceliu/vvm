AM_CPPFLAGS = -Wall -Werror -Wextra
bin_PROGRAMS = runtime
runtime_SOURCES = runtime.cpp
runtime_CPPFLAGS = -I$(top_srcdir)/build/jemalloc/include $(AM_CPPFLAGS)
runtime_LDADD = $(top_srcdir)/build/jemalloc/lib/libjemalloc.a
