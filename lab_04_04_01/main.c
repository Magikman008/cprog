#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int yes_or_no(char *string)
{
    // int len = strlen(string);
    int cur = 0;

    if (string[cur] == '-' || string[cur] == '+')
        cur++;

    int count = 0;

    while (isdigit(string[cur]))
    {
        count++;
        cur++;
    }

    if (count == 0)
    {
        if (string[cur] != '.')
            return EXIT_FAILURE;

        cur++;
        count = 0;

        while (isdigit(string[cur]))
        {
            count++;
            cur++;
        }

        if (count == 0)
            return EXIT_FAILURE;
    }
    else
    {
        if (string[cur] == '.')
            cur++;

        while (isdigit(string[cur]))
        {
            cur++;
        }
    }

    if (string[cur] == 0)
        return EXIT_SUCCESS;
    if (string[cur] != 'E' && string[cur] != 'e')
        return EXIT_FAILURE;
    cur++;
    if (string[cur] == '-' || string[cur] == '+')
        cur++;

    count = 0;

    while (isdigit(string[cur]))
    {
        count++;
        cur++;
    }

    if (count == 0)
        return EXIT_FAILURE;
    if (string[cur] != 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
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
    rc = yes_or_no(string);

    if (rc)
        puts("NO");
    else
        puts("YES");

    return EXIT_SUCCESS;
}