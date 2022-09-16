#include "process_file.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
        return ERROR_WRONG_ARGS;

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return ERROR_EMPTY_FILE;

    size_t count = 0;
    good_t products[MAX_ARRAY_LEN];
    int rc;

    if ((rc = scan(f, &count, products)))
        return rc;

    if ((rc = print_answer(count, products, argv[2])))
        return rc;

    if (fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    return EXIT_SUCCESS;
}
