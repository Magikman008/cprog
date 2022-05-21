#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_OF_STR 257
#define MAX_LEN_OF_WORD 17

#define ERROR_EMPTY_STRING -1
#define ERROR_TOO_BIG_WORD -2
#define ERROR_NO_WORDS -3

int input_str(char *string)
{
    if (!fgets(string, MAX_LEN_OF_STR, stdin))
        return ERROR_EMPTY_STRING;

    size_t len = strlen(string);

    if (string[len - 1] == '\n')
        string[--len] = '\0';

    return EXIT_SUCCESS;
}

int strsplt(const char *const string, size_t *number_words, char (*words)[MAX_LEN_OF_WORD])
{
    *number_words = 0;
    size_t len_word = 0;
    char seps[] = ",;:-.!? ";
    char word[MAX_LEN_OF_WORD];
    for (size_t i = 0; string[i] != '\0'; i++)
    {
        if (strchr(seps, string[i]) == NULL)
        {
            if (len_word + 2 > MAX_LEN_OF_WORD)
                return ERROR_TOO_BIG_WORD;

            word[len_word++] = string[i];
        }
        else
        {
            word[len_word] = '\0';

            if (strlen(word) != 0)
                strcpy(words[(*number_words)++], word);

            len_word = 0;
        }
    }

    word[len_word] = '\0';

    if (strlen(word) != 0)
        strcpy(words[(*number_words)++], word);

    if (*number_words == 0)
        return ERROR_NO_WORDS;

    return EXIT_SUCCESS;
}

void store_unique(char (*words)[MAX_LEN_OF_WORD], size_t *number_words)
{
    int i = *number_words - 1;
    while (i >= 0)
    {
        int count = 0;

        for (int j = i - 1; j >= 0; j--)
            if (strcmp(words[j], words[i]) == 0)
                count++;

        if (count != 0)
        {
            printf("i = %d\n", i);
            for (size_t k = i; k < *number_words - 1; k++)
            {
                printf("%ld\n", k);
                strcpy(words[k], words[k + 1]);
            }
            *number_words = *number_words - 1;
            for (size_t i = 0; i < *number_words; i++)
                printf("%s ", words[i]);
            puts("");
        }
        i--;
    }
}

void sort(char (*words)[MAX_LEN_OF_WORD], const size_t number_words)
{
    char temp[MAX_LEN_OF_WORD];
    for (size_t i = 0; i < number_words; i++)
        for (size_t j = i + 1; j < number_words; j++)
            if (strcmp(words[i], words[j]) > 0)
            {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
}

int main(void)
{
    char string[MAX_LEN_OF_STR];
    int rc;
    rc = input_str(string);

    if (rc != EXIT_SUCCESS)
        return rc;

    char words[MAX_LEN_OF_STR / 2][MAX_LEN_OF_WORD];
    size_t number_words = 0;

    rc = strsplt(string, &number_words, words);

    if (rc != EXIT_SUCCESS)
        return rc;

    store_unique(words, &number_words);
    sort(words, number_words);
    printf("%s", "Result: ");

    for (size_t i = 0; i < number_words; i++)
        printf("%s ", words[i]);

    return EXIT_SUCCESS;
}