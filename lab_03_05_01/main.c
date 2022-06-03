#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_BIG_VALUE -1
#define ERROR_TOO_LITTLE_VALUE -2
#define ERROR_WRONG_INPUT -3
#define ERROR_NO_SUITABLE_NUMBERS -4

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

    if (rc == EXIT_SUCCESS)
    {
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

int add_items_to_array(int (*matrix)[MAX_LEN_OF_ARR], const size_t rows, const size_t columns, int *arr, size_t *count)
{
    int rc = EXIT_SUCCESS;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (sum_digits(abs(*(*(matrix + i) + j))) > 10)
            {
                *(arr + *count) = *(*(matrix + i) + j);
                (*count)++;
            }

    if (*count == 0)
        rc = ERROR_NO_SUITABLE_NUMBERS;

    return rc;
}

void shift_array(int *arr, const size_t count)
{
    for (int j = 0; j < 3; j++)
    {
        int temp0 = *(arr);

        for (size_t i = 0; i < count - 1; i++)
            *(arr + i) = *(arr + i + 1);

        *(arr + count - 1) = temp0;
    }
}

void add_items_to_matrix(int (*matrix)[MAX_LEN_OF_ARR], const size_t rows, const size_t columns, int *arr)
{
    size_t count = 0;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (sum_digits(abs(*(*(matrix + i) + j))) > 10)
            {
                *(*(matrix + i) + j) = *(arr + count);
                count++;
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

    int arr[MAX_LEN_OF_ARR * MAX_LEN_OF_ARR];
    size_t count = 0;

    if (rc == EXIT_SUCCESS)
        rc = add_items_to_array(matrix, rows, columns, arr, &count);

    if (rc == EXIT_SUCCESS)
    {
        shift_array(arr, count);
        add_items_to_matrix(matrix, rows, columns, arr);
        show_matrix(matrix, rows, columns);
    }

    return rc;
}
