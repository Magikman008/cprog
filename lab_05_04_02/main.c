#include "case.h"

int main(int argc, char **argv)
{
    int rc;

    // if (argc == 4 && strcmp(argv[1], "ft") == 0)
    // {
    //     rc = case_ft(argv[2], argv[3]);
    //     if (rc)
    //         return rc;
    // }
    if (argc == 4 && strcmp(argv[1], "st") == 0)
    {
        rc = case_st(argv[2], argv[3]);
        if (rc)
            return rc;
    }
    // else if (argc == 3 && strcmp(argv[1], "at") == 0)
    // {
    //     rc = case_at(argv[2]);
    //     if (rc)
    //         return rc;
    // }
    else
        return ERROR_WRONG_ARGS;

    return EXIT_SUCCESS;
}
