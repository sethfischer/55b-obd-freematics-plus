#!/usr/bin/env bash

set -o errexit -o noclobber

platformio run --environment=freematics_one_plus --environment=freematics_one_plus_debug
