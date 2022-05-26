#ifndef _PRINT_FILE_H_
#define _PRINT_FILE_H_

#include <stdio.h>

#define ERROR_NO_FILE -1
#define ERROR_EMPTY_FILE -2
#define ERROR_NO_NUMBERS -3

int print_file(FILE *f);

#endif