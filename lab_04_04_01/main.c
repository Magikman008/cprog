#include <stdio.h>
#include <string.h>
#include "exp_notation.h"

#define MAX_LEN_OF_STR 257
#define MAX_LEN_OF_WORD 17

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
    {
        return ERROR_TOO_BIG_STR;
    }

    if (string[len - 1] == '\n')
        string[--len] = '\0';

    return EXIT_SUCCESS;
}

void change_string(char *string)
{
    size_t i = 0;

    while (isspace(string[i]))
        for (size_t k = i; k < MAX_LEN_OF_STR - 1; k++)
            string[k] = string[k + 1];

    i = strlen(string) - 1;

    while (isspace(string[i]))
    {
        string[i] = '\0';
        i--;
    }
}

int main(void)
{
    char string[MAX_LEN_OF_STR];
    int rc;
    rc = input_str(string);

    if (rc != EXIT_SUCCESS)
        return rc;

    if (strlen(string) == 0)
    {
        puts("NO");
        return EXIT_SUCCESS;
    }

    change_string(string);
    rc = isnumber(string);

    if (rc)
        puts("NO");
    else
        puts("YES");

    return EXIT_SUCCESS;
}
