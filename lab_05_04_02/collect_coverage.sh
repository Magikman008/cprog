#!/bin/bash

./clean.sh
./build_debug.sh
rm -rf main.gcda
./func_tests/scripts/func_tests.sh
echo
gcov -rkH main.c add_to_file.c case.c print_file.c sort_file.c
