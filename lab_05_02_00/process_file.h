#ifndef _PROCESS_FILE_H_
#define _PROCESS_FILE_H_

#include <stdio.h>

#define ERROR_NO_FILE -1
#define ERROR_EMPTY_FILE -2
#define ERROR_NO_NUMBERS -3
#define ERROR_BAD_FCLOSE -4

int find_average(FILE *f, float *average);
int find_nearest(FILE *f, const float average, float *nearest);

#endif