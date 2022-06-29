#ifndef _TRANSLATOR_H_
#define _TRANSLATOR_H_

#define FORMAT_LEN 5
#define MAX_LEN_STR 20
#define MAX_FORMATS 20

#define ERROR_WRONG_ARGS 53
#define ERROR_NO_FILE -2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int text_to_bin(FILE *in, FILE *out, char (*formats)[FORMAT_LEN], int number);
int bin_to_text(FILE *in, FILE *out, char (*formats)[FORMAT_LEN], int number);

#endif
