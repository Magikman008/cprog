#include "exp_notation.h"

int isnumber(char *string)
{
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