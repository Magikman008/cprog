#ifndef _PRINT_FILE_H_
#define _PRINT_FILE_H_

#define EXPECTED_SCANF_RESULT 1

#define MAX_SIZE_OF_FILE 100000
#define MAX_SIZE_NAME 31
#define MAX_SIZE_MANUFAC 16

#define ERROR_WRONG_ARGS 53
#define ERROR_NO_FILE -2
#define ERROR_BAD_FILE -3
#define ERROR_WRONG_INPUT -4
#define ERROR_BAD_FCLOSE -5
#define ERROR_EMPTY_STRING -6
#define ERROR_TOO_LONG_STRING -7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct
{
    char name[MAX_SIZE_NAME];
    char manufac[MAX_SIZE_MANUFAC];
    uint32_t amount;
    uint32_t number;
} good_t;

int print_file(good_t *goods, size_t count, char *substr);
void count_numbers(FILE *f, size_t *count);
int add_to_array(FILE *f, size_t count, good_t *goods);

#endif
