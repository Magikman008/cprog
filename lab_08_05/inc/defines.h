#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define EXPECTED_SCANF 3

#define ERROR_WRONG_SIZES -1
#define ERROR_ALLOC_MATRIX -2
#define ERROR_MULT_MATRIX -3
#define ERROR_NO_ITEMS -4
#define ERROR_MALLOC -6
#define ERROR_NO_PRINT -7
#define ERROR_ZERO -8
#define ERROR_SCANF -9
#define ERROR_WRONG_POWERS -10

#ifdef DEBUG
#define LOG(...)            \
    {                       \
        printf(__VA_ARGS__); \
    }
#else
#define LOG(...) \
    {            \
    }
#endif

#endif
