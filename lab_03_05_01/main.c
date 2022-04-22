#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_BIG_VALUE -1
#define ERROR_TOO_LITTLE_VALUE -2
#define ERROR_WRONG_INPUT -3
#define ERROR_NO_SUITABLE_NUMBERS -4

int length_input(size_t *rows, size_t *columns)
{
    printf("Input number of rows: ");
    int rc = scanf("%zu", rows);

    if (rc != EXPECTED_SCANF_RESULT)
    {
        puts("Wrong input");
        return ERROR_WRONG_INPUT;
    }

    printf("Input number of columns: ");
    rc = scanf("%zu", columns);

    if (rc != EXPECTED_SCANF_RESULT)
    {
        puts("Wrong input");
        return ERROR_WRONG_INPUT;
    }

    if (*rows < 1 || *columns < 1)
    {
        puts("Length of array must be over zero");
        return ERROR_TOO_LITTLE_VALUE;
    }
    if (*rows > MAX_LEN_OF_ARR || *columns > MAX_LEN_OF_ARR)
    {
        puts("Length of array must be under or equal ten");
        return ERROR_TOO_BIG_VALUE;
    }

    return EXIT_SUCCESS;
}

int input_arr(int (*matrix)[MAX_LEN_OF_ARR], size_t rows, size_t columns)
{
    int rc;
    puts("Input your items: ");
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
        {
            rc = scanf("%d", (*(matrix + i) + j));
            if (rc != EXPECTED_SCANF_RESULT)
            {
                printf("Wrong input\n");
                return ERROR_WRONG_INPUT;
            }
        }

    return EXIT_SUCCESS;
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

int add_items_to_arr(int (*matrix)[MAX_LEN_OF_ARR], size_t rows, size_t columns, int *arr, size_t *count)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (sum_digits(*(*(matrix + i) + j)) > 10)
            {
                *(arr + *count) = *(*(matrix + i) + j);
                (*count)++;
            }
    if (*count == 0)
        return ERROR_NO_SUITABLE_NUMBERS;
    return EXIT_SUCCESS;
}

void arr_shift(int *arr, size_t count)
{
    int temp0 = *(arr);
    int temp1 = *(arr + 1);
    int temp2 = *(arr + 2);
    for (size_t i = 0; i < count - 3; i++)
        *(arr + i) = *(arr + i + 3);
    *(arr + count - 3) = temp0;
    *(arr + count - 2) = temp1;
    *(arr + count - 1) = temp2;
}

void add_items_to_matrix(int (*matrix)[MAX_LEN_OF_ARR], size_t rows, size_t columns, int *arr)
{
    size_t count = 0;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (sum_digits(*(*(matrix + i) + j)) > 10)
            {
                *(*(matrix + i) + j) = *(arr + count);
                count++;
            }
}

void show_matrix(int (*matrix)[MAX_LEN_OF_ARR], size_t rows, size_t columns)
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
    int rc;

    rc = length_input(&rows, &columns);
    if (rc != EXIT_SUCCESS)
        return rc;

    int matrix[MAX_LEN_OF_ARR][MAX_LEN_OF_ARR];
    int arr[MAX_LEN_OF_ARR * MAX_LEN_OF_ARR];
    rc = input_arr(matrix, rows, columns);
    if (rc != EXIT_SUCCESS)
        return rc;

    size_t count = 0;
    rc = add_items_to_arr(matrix, rows, columns, arr, &count);
    if (rc != EXIT_SUCCESS)
        return rc;
    arr_shift(arr, count);
    add_items_to_matrix(matrix, rows, columns, arr);
    show_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}
