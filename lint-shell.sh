#!/usr/bin/env bash

set -e
shopt -s globstar

directory="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

git ls-files -z -- "${directory}/**.sh" | xargs --no-run-if-empty --null shellcheck
