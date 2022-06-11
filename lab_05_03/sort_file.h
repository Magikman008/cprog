#ifndef _PROCESS_SEQUENCE_H_
#define _PROCESS_SEQUENCE_H_

#include <stdio.h>

#define ERROR_WRONG_POS -1

int get_number_by_pos(FILE *f, int pos, int *num);
int put_number_by_pos(FILE *f, int pos, int number);
int sort_file(char *file, size_t count);

#endif