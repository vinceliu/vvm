AM_CPPFLAGS = -Wall -Werror -Wextra
bin_PROGRAMS = runtime
runtime_SOURCES = runtime.cpp
runtime_CPPFLAGS = -I$(top_srcdir)/build/jemalloc/include $(AM_CPPFLAGS)
runtime_LDADD = $(top_srcdir)/build/jemalloc/lib/libjemalloc.a

lib_LTLIBRARIES = libjvm.la
libjvm_la_SOURCES = runtime.cpp
libjvm_la_CPPFLAGS = -fPIC -I$(top_srcdir)/build/jemalloc/include $(AM_CPPFLAGS)
libjvm_la_LDFLAGS = -fPIC -version-info 0:0:0
libjvm_la_LIBADD = $(top_srcdir)/build/jemalloc/lib/libjemalloc_pic.a
