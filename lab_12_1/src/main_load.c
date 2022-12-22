#include "../inc/headers.h"
#include <dlfcn.h>

typedef int (*read_array_t)(const char *const, size_t *const, int **);
typedef int (*key_t)(const int *, const int *, int **, int **);
typedef void (*mysort_t)(void *, size_t, size_t, int (*)(const void *, const void *));
typedef int (*print_file_t)(const char *const, int *, const int *);
typedef int (*compare_int_t)(const void *, const void *);
typedef int (*parse_args_t)(const int, char **const);

#define FILTER_FUNC                                         \
    do                                                      \
    {                                                       \
        if (argc == 4)                                      \
        {                                                   \
            rc = key(nums, nums + count, &pb_dst, &pe_dst); \
            free(nums);                                     \
                                                            \
            if (rc)                                         \
            {                                               \
                dlclose(hlib);                              \
                return rc;                                  \
            }                                               \
        }                                                   \
    } while (0);

#define IFRC           \
    do                 \
    {                  \
        if (rc)        \
            return rc; \
    } while (0)

#define IFNULL(func)               \
    do                             \
    {                              \
        if (!(func))               \
        {                          \
            dlclose(hlib);         \
            return ERROR_GET_FUNC; \
        }                          \
    } while (0)

int main(int argc, char **argv)
{
    int rc = 0;

    void *hlib;
    read_array_t read_array;
    key_t key;
    mysort_t mysort;
    print_file_t print_file;
    compare_int_t compare_int;
    parse_args_t parse_args;

    hlib = dlopen("./out/libfuncs.so", RTLD_NOW);

    if (!hlib)
        return ERROR_OPENLIB;

    read_array = (read_array_t)dlsym(hlib, "read_array");
    IFNULL(read_array);
    key = (key_t)dlsym(hlib, "key");
    IFNULL(key);
    mysort = (mysort_t)dlsym(hlib, "mysort");
    IFNULL(mysort);
    print_file = (print_file_t)dlsym(hlib, "print_file");
    IFNULL(print_file);
    compare_int = (compare_int_t)dlsym(hlib, "compare_int");
    IFNULL(compare_int);
    parse_args = (parse_args_t)dlsym(hlib, "parse_args");
    IFNULL(parse_args);

    if ((rc = parse_args(argc, argv)))
        return rc;

    size_t count = 0;
    int *nums = NULL;

    if ((rc = read_array(argv[1], &count, &nums)))
    {
        dlclose(hlib);
        return rc;
    }

    int *pb_dst = nums, *pe_dst = nums + count;

    FILTER_FUNC

    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare_int);
    rc = print_file(argv[2], pb_dst, pe_dst);
    free(pb_dst);
    dlclose(hlib);
    IFRC;
    return EXIT_SUCCESS;
}
