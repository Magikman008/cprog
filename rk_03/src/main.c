#include "../inc/header.h"
#include "../inc/readprint.h"
#include "../inc/funcs.h"

// вариант 5, ввод и хранение 1, задание 1 минимум, задание 2 ряды, вывод 1
// https://youtu.be/dQw4w9WgXcQ

int main(void)
{
    FILE *f = fopen("in.txt", "r");

    int n, m;
    fscanf(f, "%d %d\n", &n, &m);

    int **ptrs = allocate_matrix(n, m);

    read_matrix(ptrs, n, m, f);

    fclose(f);

    f = fopen("out.txt", "w");

    print_matrix(ptrs, n, m, f);

    free(ptrs[0]);
    free(ptrs);
    fclose(f);

    return EXIT_SUCCESS;
}
