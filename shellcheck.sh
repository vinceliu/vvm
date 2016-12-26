#!/bin/bash

# Only run shellcheck in Linux
if [[ $TRAVIS_OS_NAME == "linux" ]]; then
    apt-add-repository "deb http://archive.ubuntu.com/ubuntu trusty-backports main restricted universe multiverse"
    apt-get -qq update
    apt-get -t trusty-backports install shellcheck
    apt-get install libpthread-stubs0-dev

    shellcheck shellcheck.sh build.sh build_googletest.sh
fi
