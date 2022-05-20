#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_LEN_OF_STR 257
#define MAX_LEN_OF_WORD 17

#define ERROR_EMPTY_STRING -1
#define ERROR_TOO_BIG_WORD -2
#define ERROR_TOO_LITTLE_WORDS -3

int input_str(char *string)
{
    if (!fgets(string, MAX_LEN_OF_STR, stdin))
        return ERROR_EMPTY_STRING;

    size_t len = strlen(string);

    if (string[len - 1] == '\n')
        string[--len] = '\0';

    return EXIT_SUCCESS;
}

void change_string(char *string)
{
    size_t i = 0;
    while (string[i] != '\0')
    {
        if (isspace(string[i]))
        {
            for (size_t k = i; k < MAX_LEN_OF_STR - 1; k++)
                string[k] = string[k + 1];
        }
        else
            i++;
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
        return ERROR_EMPTY_STRING;

    change_string(string);
    printf("%s\n", string);
    rc = regexec((regex_t *)string, "[+-]?(\\d+([.]\\d*)?([eE][+-]?\\d+)?|[.]\\d+([eE][+-]?\\d+)?)", 0, NULL, 0);

    if (rc == 0)
        puts("Yes");
    else
        puts("No");

    return EXIT_SUCCESS;
}