#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_BIG_VALUE -1
#define ERROR_TOO_LITTLE_VALUE -2
#define ERROR_WRONG_INPUT -3
#define ERROR_NOT_SQUARE -4

int input_length(size_t *side)
{
    printf("Input number of rows: ");
    int rc = EXIT_SUCCESS;
    int tmp = scanf("%zu", side);

    if (tmp != EXPECTED_SCANF_RESULT)
    {
        printf("Wrong input\n");
        rc = ERROR_WRONG_INPUT;
    }

    size_t columns;
    printf("Input number of columns: ");
    tmp = scanf("%zu", &columns);

    if (tmp != EXPECTED_SCANF_RESULT)
    {
        printf("Wrong input\n");
        rc = ERROR_WRONG_INPUT;
    }

    if (*side < 1 || columns < 1)
    {
        printf("Length of array must be over zero\n");
        rc = ERROR_TOO_LITTLE_VALUE;
    }

    if (*side > MAX_LEN_OF_ARR || columns > MAX_LEN_OF_ARR)
    {
        printf("Length of array must be under or equal ten\n");
        rc = ERROR_TOO_BIG_VALUE;
    }

    if (*side != columns)
    {
        puts("Numner of rows and columns must be equal");
        rc = ERROR_NOT_SQUARE;
    }

    return rc;
}

int input_matrix(int (*matrix)[MAX_LEN_OF_ARR], const size_t side)
{
    int rc = EXIT_SUCCESS, tmp;
    puts("Input your items: ");

    for (size_t i = 0; i < side && rc == EXIT_SUCCESS; i++)
        for (size_t j = 0; j < side && rc == EXIT_SUCCESS; j++)
        {
            tmp = scanf("%d", (*(matrix + i) + j));

            if (tmp != EXPECTED_SCANF_RESULT)
            {
                printf("Wrong input\n");
                rc = ERROR_WRONG_INPUT;
            }
        }
    return EXIT_SUCCESS;
}

void replace_rows(int (*matrix)[MAX_LEN_OF_ARR], const size_t side)
{
    for (size_t i = 0; i < side / 2; i++)
        for (size_t j = i; j < side - i; j++)
        {
            int temp = *(*(matrix + side - i - 1) + j);
            *(*(matrix + side - i - 1) + j) = *(*(matrix + i) + j);
            *(*(matrix + i) + j) = temp;
        }
}

void show_matrix(int (*matrix)[MAX_LEN_OF_ARR], const size_t side)
{
    for (size_t i = 0; i < side; i++)
    {
        for (size_t j = 0; j < side; j++)
            printf("%d ", *(*(matrix + i) + j));
        puts("");
    }
}

int main(void)
{
    size_t side;
    int rc = EXIT_SUCCESS;
    rc = input_length(&side);
    int matrix[MAX_LEN_OF_ARR][MAX_LEN_OF_ARR];

    if (rc == EXIT_SUCCESS)
        rc = input_matrix(matrix, side);

    if (rc == EXIT_SUCCESS)
    {
        replace_rows(matrix, side);
        show_matrix(matrix, side);
    }

    return rc;
}
