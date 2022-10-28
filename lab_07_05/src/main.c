#include "../inc/headers.h"
#include "../inc/funcs.h"

int main(int argc, char **argv)
{
    FILE *dist, *src;

    if (argc != 3 && argc != 4)
        return ERROR_BAD_ARGS;

    if (argc == 4 && strcmp(argv[3], "f"))
        return ERROR_BAD_ARGS;

    if (!(src = fopen(argv[1], "r")))
        return ERROR_FILE_OPEN;

    if (!(dist = fopen(argv[2], "w")))
    {
        if (fclose(src))
            return ERROR_FILE_CLOSE;

        return ERROR_FILE_OPEN;
    }

    size_t count = 0;
    int rc = count_elems(src, &count);

    if (rc)
        return rc;

    LOG("%ld\n", count);

    int *nums = NULL;
    nums = malloc(count * sizeof(int));

    if (NULL == nums)
    {
        if (fclose(src))
            return ERROR_FILE_CLOSE;
        if (fclose(dist))
            return ERROR_FILE_CLOSE;
        return ERROR_MALLOC;
    }

    rewind(src);
    rc = read_array(src, nums, nums + count);

    if (fclose(src))
        return ERROR_FILE_CLOSE;

    if (rc)
    {
        if (fclose(dist))
            return ERROR_FILE_CLOSE;

        return rc;
    }

#ifdef DEBUG
    for (size_t i = 0; nums + i < nums + count; i++)
        printf("%d ", *(nums + i));
    puts("");
#endif

    int *pb_dst = nums, *pe_dst = nums + count;

    if (argc == 4)
    {
        rc = key(nums, nums + count, &pb_dst, &pe_dst);
        free(nums);

        if (rc)
            return rc;
    }
#ifdef DEBUG
    for (size_t i = 0; pb_dst + i < pe_dst; i++)
        printf("%d ", *(pb_dst + i));
    puts("");
#endif

    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare_int);

#ifdef DEBUG
    for (size_t i = 0; pb_dst + i < pe_dst; i++)
        printf("%d ", *(pb_dst + i));
#endif

    print_file(dist, pb_dst, pe_dst);

    if (fclose(dist))
        return ERROR_FILE_CLOSE;

    return EXIT_SUCCESS;
}
