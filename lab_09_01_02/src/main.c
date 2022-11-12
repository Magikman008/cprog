#include "../inc/funcs.h"

int main(int argc, char **argv)
{
    FILE *src;

    if (argc != 2 && argc != 3)
        return ERROR_BAD_ARGS;

    if (!(src = fopen(argv[1], "r")))
        return ERROR_FILE_OPEN;

    size_t count = 0;
    int rc = count_elems(src, &count);

    if (rc)
    {
        if (fclose(src))
            return ERROR_FILE_CLOSE;

        return rc;
    }

    item_t *items = (item_t *)malloc(sizeof(item_t) * count);
    rewind(src);

    read_array(src, items, count);

    if (fclose(src))
    {
        free_items(items, count);
        return ERROR_FILE_CLOSE;
    }

    int all = 0;
    if (argc == 3)
    {
        char *lower = calloc(strlen(argv[2]) + 1, sizeof(char));

        for (size_t i = 0; i < strlen(argv[2]); i++)
            lower[i] = tolower((unsigned char)argv[2][i]);

        if (strcmp(lower, "all") == 0)
            all = 1;

        free(lower);
    }

    if (argc == 3 && all)
    {
        rc = print_filtered_array(items, count, "");

        if (rc)
        {
            free_items(items, count);
            return rc;
        }
    }
    else if (argc == 3)
    {
        rc = print_filtered_array(items, count, argv[2]);

        if (rc)
        {
            free_items(items, count);
            return rc;
        }
    }
    else
    {
        sort_array(items, count);
        rc = print_filtered_array(items, count, "");

        if (rc)
        {
            free_items(items, count);
            return rc;
        }
    }

    free_items(items, count);
    return EXIT_SUCCESS;
}
