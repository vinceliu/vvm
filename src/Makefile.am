if ASAN
_asan_debug_flags=-fsanitize=address \
             -fsanitize=alignment -fsanitize=bool \
             -fsanitize=bounds -fsanitize=enum -fsanitize=enum \
             -fsanitize=float-cast-overflow -fsanitize=float-divide-by-zero \
             -fsanitize=nonnull-attribute -fsanitize=null \
             -fsanitize=object-size -fsanitize=return \
             -fsanitize=returns-nonnull-attribute -fsanitize=shift \
             -fsanitize=signed-integer-overflow -fsanitize=unreachable \
             -fsanitize=unsigned-integer-overflow -fsanitize=vla-bound \
             -fsanitize=vptr
_asan_debug_ldflags=-fsanitize-memory-track-origins
else
_asan_debug_flags=
_asan_debug_ldflags=
endif

AM_CPPFLAGS = -Wall -Werror -Wextra $(_asan_debug_flags)
bin_PROGRAMS = runtime
runtime_SOURCES = runtime.cpp
runtime_CPPFLAGS = -I$(top_srcdir)/build/jemalloc/include \
                   -I$(top_srcdir)/include \
                   ${AM_CPPFLAGS}
#                  -I$(top_srcdir)/build/cvmi/include $(AM_CPPFLAGS)
runtime_LDFLAGS = $(_asan_debug_flags) $(_asan_debug_ldflags)
#runtime_LDADD = $(top_srcdir)/build/jemalloc/lib/libjemalloc.a

lib_LTLIBRARIES = libjvm.la
libjvm_la_SOURCES = runtime.cpp
libjvm_la_CPPFLAGS = -fPIC -I$(top_srcdir)/build/jemalloc/include \
                     -I$(top_srcdir)/include \
                     ${AM_CPPFLAGS}
#-I$(top_srcdir)/build/cvmi/include $(AM_CPPFLAGS)
libjvm_la_LDFLAGS = -fPIC -avoid-version $(_asan_debug_flags) \
                    $(_asan_debug_ldflags)
#libjvm_la_LIBADD = $(top_srcdir)/build/jemalloc/lib/libjemalloc_pic.a
