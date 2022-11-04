#include "../inc/funcs.h"

void indexesarray()
{
    puts("When и при каких условиях можно переписать");
}

int **allocate_matrix(int n, int m)
{
    int **ptrs = malloc(n * sizeof(int *));

    if (!ptrs)
        return NULL;

    int *data = malloc(n * m * sizeof(double));

    if (!data)
    {
        free(ptrs);
        return NULL;
    }

    for (int i = 0; i < n; i++)
        ptrs[i] = data + i * m;

    return ptrs;
}
