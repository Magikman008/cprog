#include "../inc/headers.h"
#include "../inc/funcs.h"

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
        return ERROR_BAD_ARGS;

    if (argc == 4 && strcmp(argv[3], "f"))
        return ERROR_BAD_ARGS;

    size_t count = 0;
    int *nums = NULL;

    int rc = read_array(argv[1], &count, &nums);

    if (rc)
        return rc;

    FILE *dist;

    if (!(dist = fopen(argv[2], "w")))
        return ERROR_FILE_OPEN;

    int *pb_dst = nums, *pe_dst = nums + count;
    free(nums);

    if (argc == 4)
    {
        rc = key(nums, nums + count, &pb_dst, &pe_dst);

        if (rc)
            return rc;
    }

    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare_int);
    print_file(dist, pb_dst, pe_dst);
    free(pb_dst);

    if (fclose(dist))
        return ERROR_FILE_CLOSE;

    return EXIT_SUCCESS;
}
