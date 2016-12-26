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

function _build_googletest {
    bash ./build_googletest.sh --keep --path="${PWD}/build/googletest"
}

function _build_dependencies {
    _build_jemalloc
    _build_googletest
}

function _build {
    _build_dependencies
    _build_runtime
}

# Main
_build
