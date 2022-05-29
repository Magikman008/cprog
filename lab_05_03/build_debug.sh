#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -O -g3 -c --coverage main.c -lm
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -O -g3 -c --coverage print_file.c -lm
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -O -g3 -c --coverage make_file.c -lm
gcc -o app.exe --coverage main.o make_file.o print_file.o -lm
