#ifndef FUNCS_H
#define FUNCS_H

#include "headers.h"

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...);

#define CCHAR(char)             \
    do                          \
    {                           \
        if (len < n - 1)        \
            temp[len++] = char; \
                                \
        toreturn++;             \
    } while (0)

#define CSTRING(tempstr)                  \
    do                                    \
    {                                     \
        i = 0;                            \
                                          \
        while (tempstr[i] != '\0')        \
        {                                 \
            if (len < n - 1)              \
                temp[len++] = tempstr[i]; \
                                          \
            i++;                          \
            toreturn++;                   \
        }                                 \
    } while (0)

#endif
