#include "case.h"

int main(int argc, char **argv)
{
    if (/*strcmp(argv[1], "st") != 0 && strcmp(argv[1], "ft") != 0 && */strcmp(argv[1], "at") != 0)
        return ERROR_WRONG_ARGS;

    if (strcmp(argv[1], "st") == 0 && argc != 4)
        return ERROR_WRONG_ARGS;

    if (strcmp(argv[1], "ft") == 0 && argc != 4)
        return ERROR_WRONG_ARGS;

    if (strcmp(argv[1], "at") == 0 && argc != 3)
        return ERROR_WRONG_ARGS;

    int rc;

    if (strcmp(argv[1], "ft") == 0)
    {
        rc = case_ft(argv[2], argv[3]);
        if (rc)
            return rc;
    }

    if (strcmp(argv[1], "st") == 0)
    {
        rc = case_st(argv[2], argv[3]);
        if (rc)
            return rc;
    }

    if (strcmp(argv[1], "at") == 0)
    {
        rc = case_at(argv[2]);
        if (rc)
            return rc;
    }

    return EXIT_SUCCESS;
}
