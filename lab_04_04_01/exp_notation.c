#include "exp_notation.h"

int issigh(const char symbol)
{
    if (symbol == '-' || symbol == '+')
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int iseeee(const char symbol)
{
    if (symbol == 'E' || symbol == 'e')
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int isdot(const char symbol)
{
    if (symbol == '.')
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int isend(const char symbol)
{
    if (symbol == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int rowofdigits(const char *string, int *shift, int *count)
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

    if (!issigh(string[cur]))
        cur++;

    int count = 0;

    rowofdigits(string, &cur, &count);

    if (count == 0)
    {
        if (isdot(string[cur]))
            return EXIT_FAILURE;

        cur++;
        count = 0;

        rowofdigits(string, &cur, &count);

        if (count == 0)
            return EXIT_FAILURE;
    }
    else
    {
        if (!isdot(string[cur]))
            cur++;

        rowofdigits(string, &cur, &count);
    }

    if (!isend(string[cur]))
        return EXIT_SUCCESS;

    if (iseeee(string[cur]))
        return EXIT_FAILURE;

    cur++;

    if (!issigh(string[cur]))
        cur++;

    count = 0;

    rowofdigits(string, &cur, &count);

    if (count == 0)
        return EXIT_FAILURE;

    if (isend(string[cur]))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
