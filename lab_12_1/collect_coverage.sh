#!/bin/bash

make debug

./func_tests/scripts/func_tests.sh
echo
gcov -rkH out/*.o
