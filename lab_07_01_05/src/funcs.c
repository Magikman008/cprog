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

int read_array(FILE *f, int *pb_src, const int *pe_src)
{
    int i = 0;

    for (; fscanf(f, "%d", pb_src + i) == EXPECTED_SCANF; i++);

    if ((i + pb_src) != pe_src)
        return ERROR_READ_FILE;

    return EXIT_SUCCESS;
}

int compare(const int *from, int amount)
{
    int sum = 0;

    for (int *i = (int *)from + 1; i < from + amount; i++)
        sum += *i;

    if (*from > sum)
        return 1;

    return 0;
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

    int *tempp = NULL;
    tempp = malloc(count * sizeof(int));

    if (tempp == NULL)
        return ERROR_MALLOC;

    copy_elems(pb_src, pe_src, tempp + count - 1);
    *pb_dst = tempp;
    *pe_dst = tempp + count;

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

    char *charp = (char *)first;

    while (k > 0)
    {
        int m = 0;

        for (int i = 0; i < k; i++)
        {
            if (comparator(charp + i * size, charp + (i + 1) * size) > 0)
            {
                swap(charp + i * size, charp + (i + 1) * size, size);
                m = i;
            }
        }

#ifdef DEBUG
        for (int i = 0; charp + i * size < charp + size * number; i++)
            printf("%d ", *(charp + i * size));
        puts("");
#endif

        k = m;
    }
}

void print_file(FILE *f, int *pb_src, const int *pe_src)
{
    for (int *i = pb_src; i < pe_src; i++)
        fprintf(f, "%d ", *i);
}
