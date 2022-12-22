#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPECTED_SCANF 1
#define NOT_SUITABLE 0
#define SUITABLE 1


#define ERROR_BAD_ARGS -1
#define ERROR_FILE_OPEN -2
#define ERROR_FILE_CLOSE -3
#define ERROR_NO_NUMBERS -4
#define ERROR_BAD_FILE -5
#define ERROR_MALLOC -6
#define ERROR_KEY_POINTERS -7
#define ERROR_READ_FILE -8
#define ERROR_OPENLIB 9
#define ERROR_GET_FUNC 10

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
