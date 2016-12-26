#!/bin/bash

# Builds google test as a dependency of the project


# Sanity
set -o nounset
set -o errexit

# Globals
KEEP_IF_EXIST=false
DOWNLOAD_PATH="/tmp/googletest"

function _mkdirs() {
    if [[ ! -d "$DOWNLOAD_PATH" ]]; then
        mkdir -pv "$DOWNLOAD_PATH"
    fi
}

function _clean() {
    if [[ "$KEEP_IF_EXIST" = false && -d "$DOWNLOAD_PATH" ]]; then
        echo "Killed ${DOWNLOAD_PATH} ${KEEP_IF_EXIST}"
        rm -rf "$DOWNLOAD_PATH"
    fi
}

function _downloadAndBuild() {
    cd "$DOWNLOAD_PATH"
    if [[ ! -f master.zip ]]; then
        wget https://github.com/google/googletest/archive/master.zip
    fi
    if [[ ! -d googletest-master ]]; then
        unzip -q master.zip
        cmake -DCMAKE_INSTALL_PREFIX="$DOWNLOAD_PATH" -Dgtest_build_samples=ON googletest-master/googletest
        make install
    fi
}

function _parseargs() {
    for i in "$@"
    do
    case $i in
        --keep)
        KEEP_IF_EXIST=true
        ;;
        --path=*)
        DOWNLOAD_PATH="${i#*=}"
        shift
        ;;
        *)
        echo "UNKNOWN OPTION '$i'"
        exit 1
        ;;
    esac
    done
}

# Main
_parseargs "$@"
_clean
_mkdirs
_downloadAndBuild
