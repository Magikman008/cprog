#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "find_words.h"

#define ERROR_NOT_EQUAL_LEN -1
#define ERROR_NOT_POLY -2

int make_arr(FILE *f, char (*arr)[WORD_LEN], size_t *count)
{
    char word[WORD_LEN];
    while (fscanf(f, "%s\n", word) == EXPECTED_SCANF_RESULT && *count <= NUMBER_OF_WORDS)
    {
        if (*count == NUMBER_OF_WORDS)
        {
            puts("Not all words were scaned");
            break;
        }
        strcpy(arr[*count], word);
        (*count)++;
    }

    return EXIT_SUCCESS;
}

int comparator(char *word1, char *word2)
{
    if (strlen(word1) != strlen(word2))
        return ERROR_NOT_EQUAL_LEN;
    size_t len = strlen(word1);
    for (size_t cur = 0; cur < len; cur++)
    {
        if (word1[cur] != word2[len - cur - 1])
            return ERROR_NOT_POLY;
    }
    return EXIT_SUCCESS;
}

int find_unique(FILE *f, char (*arr)[WORD_LEN], size_t *count)
{
    for (size_t i = 0; i < *count; i++)
        for (size_t j = i + 1; j < *count; j++)
            if (!comparator(arr[i], arr[j]))
                fprintf(f, "%s %s\n", arr[i], arr[j]);
    return EXIT_SUCCESS;
}
