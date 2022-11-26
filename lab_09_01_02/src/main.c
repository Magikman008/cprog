#include "../inc/funcs.h"

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return ERROR_BAD_ARGS;

    size_t count = 0;
    item_t *items = NULL;

    int rc = read_array(argv[1], &items, &count);

    if (rc)
        return rc;

    if (argc == 3 && strcmp(argv[2], "ALL") != 0)
    {
        items = filter_array(items, &count, argv[2]);

        if (NULL == items)
            return EXIT_FAILURE;
    }

    if (argc == 2)
        sort_array(items, count);

    print_array(items, count);
    free_items(items, count);

    return EXIT_SUCCESS;
}
