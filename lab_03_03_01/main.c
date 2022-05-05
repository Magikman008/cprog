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

int find_max_in_arr(int *arr, const size_t len)
{
    int max = *(arr);

    for (size_t i = 1; i < len; i++)
        if (*(arr + i) > max)
            max = *(arr + i);

    return max;
}

void sort_matrix(int (*matrix)[MAX_LEN_OF_ARR], const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < rows - i - 1; j++)
        {
            if (find_max_in_arr(*(matrix + j), columns) < find_max_in_arr(*(matrix + j + 1), columns))
            {
                for (size_t c = 0; c < columns; c++)
                {
                    int temp = *(*(matrix + j) + c);
                    *(*(matrix + j) + c) = *(*(matrix + j + 1) + c);
                    *(*(matrix + j + 1) + c) = temp;
                }
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
        sort_matrix(matrix, rows, columns);
        show_matrix(matrix, rows, columns);
    }

    return rc;
}
