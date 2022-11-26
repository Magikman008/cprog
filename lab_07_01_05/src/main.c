#include "../inc/headers.h"
#include "../inc/funcs.h"

#define FILTER_FUNC                                         \
    do                                                      \
    {                                                       \
        if (argc == 4)                                      \
        {                                                   \
            rc = key(nums, nums + count, &pb_dst, &pe_dst); \
            free(nums);                                     \
                                                            \
            if (rc)                                         \
                return rc;                                  \
        }                                                   \
    } while (0);

#define IFRC           \
    do                 \
    {                  \
        if (rc)        \
            return rc; \
    } while (0);

int main(int argc, char **argv)
{
    int rc = 0;

    if ((rc = parse_args(argc, argv)))
        return rc;

    size_t count = 0;
    int *nums = NULL;

    if ((rc = read_array(argv[1], &count, &nums)))
        return rc;

    int *pb_dst = nums, *pe_dst = nums + count;

    FILTER_FUNC

    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare_int);
    rc = print_file(argv[2], pb_dst, pe_dst);
    free(pb_dst);

    IFRC

    return EXIT_SUCCESS;
}
