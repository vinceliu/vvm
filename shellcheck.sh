#!/bin/bash

# Only run shellcheck in Linux
if [[ $TRAVIS_OS_NAME == "linux" ]]; then
    sudo apt-add-repository "deb http://archive.ubuntu.com/ubuntu trusty-backports main restricted universe multiverse"
    sudo apt-get -qq update
    sudo apt-get -t trusty-backports install shellcheck

    shellcheck shellcheck.sh build.sh
fi
