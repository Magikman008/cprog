#include <stdio.h>
#include "find_words.h"

#define ERROR_BAD_ARGS -1

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if (argc != 3)
        return ERROR_BAD_ARGS;

    size_t count = 0;
    char arr[NUMBER_OF_WORDS][WORD_LEN];
    make_arr(in, arr, &count);

    find_unique(out, arr, &count);

    return EXIT_SUCCESS;
}
