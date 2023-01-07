#ifndef _PROCESS_FILE_H_
#define _PROCESS_FILE_H_

#include <stdio.h>
#include <string.h>

#define MAX_SIZE_NAME 26
#define MAX_ARRAY_LEN 15
#define EXPECTED_SCANF_RESULT 1

#define ERROR_WRONG_ARGS -1
#define ERROR_EMPTY_FILE -2
#define ERROR_SCAN_PRICE -3
#define ERROR_BAD_FCLOSE -4
#define ERROR_BAD_FILE -5
#define ERROR_NAME_SCAN -6

typedef struct
{
    char name[MAX_SIZE_NAME+1];
    int price;
} good_t;

int scan(FILE *f, size_t *count, good_t *goods);
int print_answer(size_t count, good_t *goods, char *border);

#endif
