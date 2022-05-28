#ifndef _FIND_WORDS_H_
#define _FIND_WORDS_H_

#include <stdlib.h>

#define NUMBER_OF_WORDS 100
#define WORD_LEN 16
#define EXPECTED_SCANF_RESULT 1

int make_arr(FILE *f, char (*arr)[WORD_LEN], size_t *count);
int find_unique(FILE *f, char (*arr)[WORD_LEN], size_t *count);

#endif
