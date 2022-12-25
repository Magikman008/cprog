#ifndef PIVO
#define PIVO

#include <stdlib.h>
#include <stdio.h>

#define ERROR_BAD_PTRS -1
#define ERROR_OVERFLOW -2

typedef struct node_t
{
    int value;
    struct node_t *prev;
    struct node_t *next;
} node_t;


#endif
