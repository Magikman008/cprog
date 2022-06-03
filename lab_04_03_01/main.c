#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_OF_STR 257
#define MAX_LEN_OF_WORD 17
#define MAX_WORDS 128
#define SEPS ",;:-.!? "

#define ERROR_EMPTY_STRING -1
#define ERROR_TOO_BIG_WORD -2
#define ERROR_TOO_LITTLE_WORDS -3
#define ERROR_TOO_BIG_STR -4

int input_str(char *string)
{
    if (!fgets(string, MAX_LEN_OF_STR + 1, stdin))
        return ERROR_EMPTY_STRING;

    size_t len = strlen(string);

    if (string[len - 1] != '\n')
        return ERROR_TOO_BIG_STR;

    if (string[len - 1] == '\n')
        string[--len] = '\0';

    return EXIT_SUCCESS;
}

int strsplt(const char *const string, size_t *number_words, char (*words)[MAX_LEN_OF_WORD])
{
    *number_words = 0;
    size_t len_word = 0;
    char word[MAX_LEN_OF_WORD];

    for (size_t i = 0; string[i] != '\0'; i++)
        if (strchr(SEPS, string[i]) == NULL)
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

    word[len_word] = '\0';

    if (strlen(word) != 0)
        strcpy(words[(*number_words)++], word);

    if (*number_words < 2)
        return ERROR_TOO_LITTLE_WORDS;

    return EXIT_SUCCESS;
}

void change_word(char *word)
{
    int i = strlen(word) - 1;

    while (i >= 0)
    {
        int count = 0;

        for (int j = i - 1; j >= 0; j--)
            if (word[j] == word[i])
                count++;

        if (count != 0)
            for (size_t k = i; k < MAX_LEN_OF_WORD - 1; k++)
                word[k] = word[k + 1];

        i--;
    }
}

void make_string(char (*words)[MAX_LEN_OF_WORD], const size_t number_words, char *string)
{
    for (int i = number_words - 2; i >= 0; i--)
        if (strcmp(words[i], words[number_words - 1]))
        {
            change_word(words[i]);
            strcat(string, words[i]);
            strcat(string, " ");
        }
}

int main(void)
{
    char string[MAX_LEN_OF_STR];
    int rc;
    rc = input_str(string);

    if (rc != EXIT_SUCCESS)
        return rc;

    char words[MAX_WORDS][MAX_LEN_OF_WORD];
    size_t number_words = 0;

    rc = strsplt(string, &number_words, words);

    if (rc != EXIT_SUCCESS)
        return rc;

    strcpy(string, "");
    make_string(words, number_words, string);
    string[strlen(string) - 1] = '\0';

    if (strlen(string) == 0)
        return ERROR_EMPTY_STRING;

    printf("Result: %s\n", string);

    return EXIT_SUCCESS;
}
