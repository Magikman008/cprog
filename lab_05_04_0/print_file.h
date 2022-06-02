#ifndef _PRINT_FILE_H_
#define _PRINT_FILE_H_

#define EXPECTED_SCANF_RESULT 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[30];
    char manufac[15];
    unsigned int amount;
    unsigned int number;
} good_t;

int print_file(good_t *goods, size_t count, char *substr);
void count_numbers(FILE *f, size_t *count);
int add_to_array(FILE *f, size_t count, good_t *goods);

#endif