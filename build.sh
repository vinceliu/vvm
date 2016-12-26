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

# This really isn't building anything from CVMI, but simply checking that we can use CVMI
# to create the libjvm shim
function _build_cvmi {
    if [[ ! -f ../hotspot/src/share/vm/prims/jvm.h ]]; then
        echo "CVMI/hotspot isn't available"
        exit 1
    fi
    if [[ ! -d build/cvmi ]]; then
        mkdir -pv build/cvmi/include/prims
        cp -v ../hotspot/src/share/vm/prims/jvm.h build/cvmi/include/prims/_jvm.h.orig
        sed -e '/#include OS_HEADER_H(jvm)/d' < build/cvmi/include/prims/_jvm.h.orig > build/cvmi/include/prims/jvm.h
        mkdir -pv build/cvmi/include/utilities
        cp -v ../hotspot/src/share/vm/utilities/macros.hpp build/cvmi/include/utilities
        # FIXME: this isn't portable!
        cp -v /Library/Java/JavaVirtualMachines/jdk1.8.0_45.jdk/Contents/Home/include/jni.h build/cvmi/include/prims
        cp -v /Library/Java/JavaVirtualMachines/jdk1.8.0_45.jdk/Contents/Home/include/darwin/jni_md.h build/cvmi/include/prims
    fi
}

function _build_dependencies {
    _build_jemalloc
    _build_googletest
    _build_cvmi
}

function _build {
    _build_dependencies
    _build_runtime
}

# Main
_build
