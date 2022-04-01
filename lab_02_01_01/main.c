#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define TOO_BIG_VALUE -1
#define TOO_LITTLE_VALUE -2
#define WRONG_INPUT -3
#define CANT_SOLVE -4

int enter_array(int *arr, size_t len)
{
    int rc;
    int count = 0;
    printf("Input your items: ");
    for (size_t i = 0; i < len; i++)
    {
        rc = scanf("%d", &arr[i]);
        if (rc != EXPECTED_SCANF_RESULT)
        {
            printf("Wrong input\n");
            return WRONG_INPUT;
        }
        if (arr[i] % 2 == 1)
        {
            count++;
        }
    }
    if (count == 0)
    {
        printf("You must enter more then zero odd numbers\n");
        return CANT_SOLVE;
    }
    return EXIT_SUCCESS;
}

void multiply_of_odd(int *arr, size_t len, int *mult)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 1)
        {
            *mult *= arr[i];
        }
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t len;
    printf("Input length of array: ");
    int rc = scanf("%zu", &len);
    if (rc != EXPECTED_SCANF_RESULT)
    {
        printf("Wrong input\n");
        return WRONG_INPUT;
    }
    if (len < 1)
    {
        printf("Length of array must be over zero\n");
        return TOO_LITTLE_VALUE;
    }
    if (len >= MAX_LEN_OF_ARR)
    {
        printf("Length of array must be under or equal ten\n");
        return TOO_BIG_VALUE;
    }

    int arr[MAX_LEN_OF_ARR];
    if (enter_array(arr, len) != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }
    /*for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }*/

    int mult = 1; 
    multiply_of_odd(arr, len, &mult);
    printf("Answer is %d\n", mult);

    return EXIT_SUCCESS;
}