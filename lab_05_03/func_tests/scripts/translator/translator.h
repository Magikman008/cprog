#ifndef _TRANSLATOR_H_
#define _TRANSLATOR_H_

#define FORMAT_LEN 5
#define MAX_LEN_STR 20

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tb(FILE *in, FILE *out, char (*formats)[FORMAT_LEN], int number);
int bt(FILE *in, FILE *out, char (*formats)[FORMAT_LEN], int number);

#endif
