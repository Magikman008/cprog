#include "../inc/funcs.h"

int count_elems(FILE *f, size_t *count)
{
    int temp_int, rc;

    while ((rc = fscanf(f, "%d", &temp_int)) == EXPECTED_SCANF)
        (*count)++;

    if (*count == 0)
        return ERROR_NO_NUMBERS;

    if (rc != EOF)
        return ERROR_BAD_FILE;

    return EXIT_SUCCESS;
}

int read_array(const char *file, size_t *count, int **nums)
{
    FILE *src;

    if (!(src = fopen(file, "r")))
        return ERROR_FILE_OPEN;

    int rc = count_elems(src, count);

    if (rc)
    {
        if (fclose(src))
            return ERROR_FILE_CLOSE;

        return rc;
    }

    *nums = malloc(*count * sizeof(int));

    if (NULL == nums)
    {
        if (fclose(src))
            return ERROR_FILE_CLOSE;

        return ERROR_MALLOC;
    }

    rewind(src);

    int i = 0;

    for (; fscanf(src, "%d", *nums + i) == EXPECTED_SCANF; i++);

    if ((i + *nums) != (*nums + *count))
    {
        if (fclose(src))
            return ERROR_FILE_CLOSE;

        return ERROR_READ_FILE;
    }

    if (fclose(src))
        return ERROR_FILE_CLOSE;

    return EXIT_SUCCESS;
}

int compare(const int *from, int amount)
{
    int sum = 0;

    for (int *i = (int *)from + 1; i < from + amount; i++)
        sum += *i;

    if (*from > sum)
        return SUITABLE;

    return NOT_SUITABLE;
}

int find_suitable(const int *pb_src, const int *pe_src)
{
    int count = 0;

    for (int i = 2; pe_src - i >= pb_src; i++)
        if (compare(pe_src - i, i))
            count++;

    return count;
}

void copy_elems(const int *pb_src, const int *pe_src, int *tempp)
{
    int count = 0;

    for (int i = 2; pe_src - i >= pb_src; i++)
        if (compare(pe_src - i, i))
        {
            *(tempp - count) = *(pe_src - i);
            count++;
        }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if ((NULL == pb_src) || (NULL == pe_src))
        return ERROR_KEY_POINTERS;

    int count = find_suitable(pb_src, pe_src);

    if (count == 0)
        return ERROR_NO_NUMBERS;

    int *ptemp = NULL;
    ptemp = malloc(count * sizeof(int));

    if (ptemp == NULL)
        return ERROR_MALLOC;

    copy_elems(pb_src, pe_src, ptemp + count - 1);
    *pb_dst = ptemp;
    *pe_dst = ptemp + count;

    return EXIT_SUCCESS;
}

int compare_int(const void *val1, const void *val2)
{
    return (*(int *)val1 - *(int *)val2);
}

void swap(char *val1, char *val2, int size)
{
    char tmp;

    for (int i = 0; i < size; i++)
    {
        tmp = *(val1 + i);
        *(val1 + i) = *(val2 + i);
        *(val2 + i) = tmp;
    }
}

void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *))
{
    int k = number - 1;

    char *pchar = (char *)first;

    while (k > 0)
    {
        int m = 0;

        for (int i = 0; i < k; i++)
        {
            if (comparator(pchar + i * size, pchar + (i + 1) * size) > 0)
            {
                swap(pchar + i * size, pchar + (i + 1) * size, size);
                m = i;
            }
        }

#ifdef DEBUG
        for (int i = 0; pchar + i * size < pchar + size * number; i++)
            printf("%d ", *(pchar + i * size));
        puts("");
#endif

        k = m;
    }
}

int print_file(const char *file, int *pb_src, const int *pe_src)
{
    FILE *dist;

    if (!(dist = fopen(file, "w")))
        return ERROR_FILE_OPEN;

    for (int *i = pb_src; i < pe_src; i++)
        fprintf(dist, "%d ", *i);

    if (fclose(dist))
        return ERROR_FILE_CLOSE;

    return EXIT_SUCCESS;
}

int parse_args(const int argc, char **argv)
{
    if (argc != 3 && argc != 4)
        return ERROR_BAD_ARGS;

    if (argc == 4 && strcmp(argv[3], "f"))
        return ERROR_BAD_ARGS;

    return EXIT_SUCCESS;
}
