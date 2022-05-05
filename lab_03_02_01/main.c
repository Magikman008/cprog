#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_BIG_VALUE -1
#define ERROR_TOO_LITTLE_VALUE -2
#define ERROR_WRONG_INPUT -3

int input_length(size_t *rows, size_t *columns)
{
    printf("Input number of rows: ");
    int rc = EXIT_SUCCESS;
    int tmp = scanf("%zu", rows);

    if (tmp != EXPECTED_SCANF_RESULT)
    {
        puts("Wrong input");
        rc = ERROR_WRONG_INPUT;
    }

    printf("Input number of columns: ");
    tmp = scanf("%zu", columns);

    if (tmp != EXPECTED_SCANF_RESULT)
    {
        puts("Wrong input");
        rc = ERROR_WRONG_INPUT;
    }

    if (*rows < 1 || *columns < 1)
    {
        puts("Length of array must be over zero");
        rc = ERROR_TOO_LITTLE_VALUE;
    }

    if (*rows > MAX_LEN_OF_ARR || *columns > MAX_LEN_OF_ARR)
    {
        puts("Length of array must be under or equal ten");
        rc = ERROR_TOO_BIG_VALUE;
    }

    return rc;
}

int input_matrix(int (*matrix)[MAX_LEN_OF_ARR], const size_t rows, const size_t columns)
{
    int rc = EXIT_SUCCESS, tmp;
    puts("Input your items: ");

    for (size_t i = 0; i < rows && rc == EXIT_SUCCESS; i++)
        for (size_t j = 0; j < columns && rc == EXIT_SUCCESS; j++)
        {
            tmp = scanf("%d", (*(matrix + i) + j));

            if (tmp != EXPECTED_SCANF_RESULT)
            {
                printf("Wrong input\n");
                rc = ERROR_WRONG_INPUT;
            }
        }

    return rc;
}

int sum_digits(int x)
{
    int sum = 0;

    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

void find_min_sum_element(int (*matrix)[MAX_LEN_OF_ARR], const size_t rows, const size_t columns, size_t *return_i, size_t *return_j)
{
    int global_min = sum_digits(abs(*(*(matrix))));
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
        {
            int cur_sum = sum_digits(abs(*(*(matrix + i) + j)));

            if (cur_sum < global_min)
            {
                *return_i = i;
                *return_j = j;
                global_min = cur_sum;
            }
        }
}

void show_matrix(int (*matrix)[MAX_LEN_OF_ARR], const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            printf("%d ", *(*(matrix + i) + j));
        puts("");
    }
}

void remove_row_and_col(int (*matrix)[MAX_LEN_OF_ARR], size_t *rows, size_t *columns, size_t *return_i, size_t *return_j)
{
    for (size_t i = *return_i; i < *rows - 1; i++)
        for (size_t j = 0; j < *columns; j++)
            *(*(matrix + i) + j) = *(*(matrix + i + 1) + j);

    (*rows)--;

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = *return_j; j < *columns - 1; j++)
            *(*(matrix + i) + j) = *(*(matrix + i) + j + 1);

    (*columns)--;
}

int main(void)
{
    size_t rows;
    size_t columns;
    int rc = EXIT_SUCCESS;
    rc = input_length(&rows, &columns);
    int matrix[MAX_LEN_OF_ARR][MAX_LEN_OF_ARR];

    if (rc == EXIT_SUCCESS)
        rc = input_matrix(matrix, rows, columns);

    if (rc == EXIT_SUCCESS)
    {
        size_t i = 0, j = 0;
        find_min_sum_element(matrix, rows, columns, &i, &j);
        remove_row_and_col(matrix, &rows, &columns, &i, &j);
        show_matrix(matrix, rows, columns);
    }

    return rc;
}
