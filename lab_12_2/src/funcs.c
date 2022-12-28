#include "../inc/funcs.h"
#include <stdbool.h>
#include <stdio.h>

void fill_arr(unsigned long long *arr, int size)
{
    int a = 1;
    int b = 1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = a;
        a = b;
        b = a + arr[i];
    }
}

int is_cointain(int *arr, int size, int elem)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == elem)
            return true;

    return false;
}

int *copy_elems(int *dst, int *dst_size, int *src, int src_size)
{
    if (dst != NULL)
        free(dst);

    for (int i = 0; i < src_size; i++)
    {
        int temp = 0;
        for (int j = i + 1; j < src_size; j++)
            if (src[i] == src[j])
                temp++;

        if (temp == 0)
            (*dst_size)++;
    }

    dst = calloc(*dst_size, sizeof(int));
    *dst_size = 0;
    for (int i = 0; i < src_size; i++)
        if (is_cointain(dst, *dst_size, src[i]) == false)
            dst[(*dst_size)++] = src[i];

    return dst;
}
