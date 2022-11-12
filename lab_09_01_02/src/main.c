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
        return ERROR_FILE_CLOSE;

    if (argc == 3 && strcmp(argv[2], "ALL") == 0)
        print_filtered_array(items, count, "");
    else if (argc == 3)
        print_filtered_array(items, count, argv[2]);
    else
    {
        sort_array(items, count);
        print_filtered_array(items, count, "");
    }

    for (size_t i = 0; i < count; i++)
        free(items[i].name);

    free(items);

    return EXIT_SUCCESS;
}
