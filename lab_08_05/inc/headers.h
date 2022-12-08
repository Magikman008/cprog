#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define EXPECTED_SCANF 3

#define ERROR_BAD_ARGS -1
#define ERROR_FILE_OPEN -2
#define ERROR_FILE_CLOSE -3
#define ERROR_NO_ITEMS -4
#define ERROR_BAD_FILE -5
#define ERROR_MALLOC -6
#define ERROR_NO_PRINT -7
#define ERROR_ZERO -8

struct item_t
{
    char *name;
    double weight;
    double volume;
};

typedef struct item_t item_t;

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
