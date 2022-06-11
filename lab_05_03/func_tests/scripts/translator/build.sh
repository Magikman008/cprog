#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -O3 -c "$(dirname "$0")/main.c"
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -O3 -c "$(dirname "$0")/translator.c"
gcc -o "$(dirname "$0")/converter.exe" translator.o main.o