#!/bin/bash

# Sanity
set -o nounset
set -o errexit

function _build_runtime {
    if [[ ! -d build/runtime ]]; then
        autoreconf -i
        mkdir -pv build/runtime
        cd build/runtime && ../../configure
        cd -
        if [[ -d autom4te.cache ]]; then
            rm -rf aclocal.m4 autom4te.cache Makefile.in src/Makefile.in
        fi
    fi
    cd build/runtime && make
}

function _build_jemalloc {
    if [[ ! -d ../jemalloc ]]; then
        echo "Error: jemalloc repo is not found!"
        exit 1
    fi
    mkdir -pv build/jemalloc
    cd build/jemalloc
    if [[ ! -f config.status ]]; then
        ../../../jemalloc/configure --without-export --enable-debug --enable-prof
    fi
    make build_lib_static
    cd -
}

function _build_dependencies {
    _build_jemalloc
}

function _build {
    _build_dependencies
    _build_runtime
}

# Main
_build
