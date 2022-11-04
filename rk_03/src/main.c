#include "../inc/header.h"
#include "../inc/readprint.h"

// вариант 5, ввод и хранение 1, задание 1 минимум, задание 2 ряды, вывод 1
int main(void)
{
    FILE *f = fopen("in.txt", "r");

    int n, m;
    fscanf(f, "%d %d\n", &n, &m);

    int **ptrs = malloc(n * sizeof(int *));

    if (!ptrs)
        return ERROR_BAD_PTRS;

    int *data = malloc(n * m * sizeof(double));

    if (!data)
    {
        free(ptrs);
        return ERROR_BAD_PTRS;
    }

    for (int i = 0; i < n; i++)
        ptrs[i] = data + i * m;

    read_matrix(ptrs, n, m, f);

    fclose(f);

    f = fopen("out.txt", "w");

    print_matrix(ptrs, n, m, f);

    free(ptrs[0]);

    free(ptrs);

    fclose(f);

    return EXIT_SUCCESS;
}
