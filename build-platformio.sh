#!/usr/bin/env bash

set -o errexit -o noclobber

if [ "${GITHUB_WORKSPACE}x" != "x" ]; then
    cd "$GITHUB_WORKSPACE" || exit
    export PATH=$PATH:~/.platformio/penv/bin
    curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py -o get-platformio.py
    python get-platformio.py
fi

platformio platform install "espressif32"

platformio run