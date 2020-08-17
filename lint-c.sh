#!/usr/bin/env bash

shopt -s globstar

exit_code=0

# Check clang-format
for filename in **/*.{cpp,h} ; do
    if [ -f "$filename" ]; then
        echo -e "Check formatting of ${filename}"
        diff "$filename" <(clang-format -assume-filename=main.cpp "$filename") 1>&2
        # shellcheck disable=SC2181
        if [ $? -ne 0 ]; then
            exit_code=1
            echo -e "Fail"
        else
            echo -e "Pass"
        fi
    fi
done

exit $exit_code
