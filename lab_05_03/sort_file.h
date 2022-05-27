#ifndef _PROCESS_SEQUENCE_H_
#define _PROCESS_SEQUENCE_H_

#include <stdio.h>

int find_average(FILE *f, float *average);
int find_nearest(FILE *f, const float average, float *nearest);

#endif