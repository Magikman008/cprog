#include "exp_notation.h"

int isSigh(const char symbol)
{
    if (symbol == '-' || symbol == '+')
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int isEeee(const char symbol)
{
    if (symbol == 'E' || symbol == 'e')
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int isDot(const char symbol)
{
    if (symbol == '.')
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int isEnd(const char symbol)
{
    if (symbol == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int rowOfDigits(const char *string, int *shift, int *count)
{
    while (isdigit(string[*shift]))
    {
        (*count)++;
        (*shift)++;
    }

    return EXIT_SUCCESS;
}

int isnumber(char *string)
{
    int cur = 0;

    if (!isSigh(string[cur]))
        cur++;

    int count = 0;

    rowOfDigits(string, &cur, &count);

    if (count == 0)
    {
        if (isDot(string[cur]))
            return EXIT_FAILURE;

        cur++;
        count = 0;

        rowOfDigits(string, &cur, &count);

        if (count == 0)
            return EXIT_FAILURE;
    }
    else
    {
        if (!isDot(string[cur]))
            cur++;

        rowOfDigits(string, &cur, &count);
    }

    if (!isEnd(string[cur]))
        return EXIT_SUCCESS;

    if (isEeee(string[cur]))
        return EXIT_FAILURE;

    cur++;

    if (!isSigh(string[cur]))
        cur++;

    count = 0;

    rowOfDigits(string, &cur, &count);

    if (count == 0)
        return EXIT_FAILURE;

    if (isEnd(string[cur]))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}