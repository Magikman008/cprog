#!/bin/bash

ERROR_ONLY_MEM_OK=1
ERROR_ONLY_TEST_OK=2
ERROR_NOTHING_OK=3
ERROR_TOO_LITTLE_PARAMS=4
ERROR_FILES_DONT_EXIST=5

if [ "$#" -lt 2 ]; then
    exit $ERROR_TOO_LITTLE_PARAMS
fi

if ! [ -f "$1" ] || ! [ -f "$2" ]; then
    exit $ERROR_FILES_DONT_EXIST
fi

args=

if [ -n "$3" ]; then
    if ! [ -f "$3" ]; then
        exit $ERROR_FILES_DONT_EXIST
    fi

    args="$(cat "$3")"
    read -r -a args_arr <<<$args
    eval "$(dirname "$0")/translator/converter.exe t2b ${args_arr[1]} $(dirname "$0")/temp.bin d"
fi

if [ -n "${USE_VALGRIND}" ]; then
    valgrind --leak-check=full --leak-resolution=med --log-file="$(dirname "$0")/report.txt" --quiet "$(dirname "$0")/../../app.exe"  "${args_arr[0]}" "$(dirname "$0")/temp.bin" <"$1" >"$(dirname "$0")/result.txt"

    if [ -z "$(cat "$(dirname "$0")/report.txt")" ]; then
        if [ "${args_arr[0]}" = "p" ]; then
            if ! "$(dirname "$0")/comparator.sh" "$(dirname "$0")/result.txt" "$2"; then
                exit $ERROR_ONLY_MEM_OK
            fi
        elif [ "${args_arr[0]}" = "s" ]; then
            eval "$(dirname "$0")/translator/converter.exe b2t $(dirname "$0")/temp.bin $(dirname "$0")/temp.txt d"
            if ! "$(dirname "$0")/comparator.sh" "$(dirname "$0")/temp.txt" "$2"; then
                exit $ERROR_ONLY_MEM_OK
            fi
        fi
    elif [ "${args_arr[0]}" = "p" ]; then
        if "$(dirname "$0")/comparator.sh" "$(dirname "$0")/result.txt" "$2"; then
            exit $ERROR_ONLY_TEST_OK
        fi
    elif [ "${args_arr[0]}" = "s" ]; then
        eval "$(dirname "$0")/translator/converter.exe b2t $(dirname "$0")/temp.bin $(dirname "$0")/temp.txt d"
        if "$(dirname "$0")/comparator.sh" "$(dirname "$0")/temp.txt" "$2"; then
            exit $ERROR_ONLY_TEST_OK
        fi
    else
        exit $ERROR_NOTHING_OK
    fi
else
    "$(dirname "$0")/../../app.exe" "${args_arr[0]}" "$(dirname "$0")/temp.bin" <"$1" >"$(dirname "$0")/result.txt"
    if [ "${args_arr[0]}" = "p" ]; then
        if ! "$(dirname "$0")/comparator.sh" "$(dirname "$0")/result.txt" "$2"; then
            exit $ERROR_ONLY_MEM_OK
        fi
    elif [ "${args_arr[0]}" = "s" ]; then
        eval "$(dirname "$0")/translator/converter.exe b2t $(dirname "$0")/temp.bin $(dirname "$0")/temp.txt d"
        if ! "$(dirname "$0")/comparator.sh" "$(dirname "$0")/temp.txt" "$2"; then
            exit $ERROR_ONLY_MEM_OK
        fi
    fi
fi
