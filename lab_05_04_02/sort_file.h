#ifndef _PROCESS_SEQUENCE_H_
#define _PROCESS_SEQUENCE_H_

#include "print_file.h"

#define ERROR_WRONG_POS -1

int sort_file(good_t *goods, size_t count);
int write_file(FILE *f, good_t *goods, size_t count);

#endif
