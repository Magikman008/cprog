#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define TOO_BIG_VALUE -1
#define TOO_LITTLE_VALUE -2
#define WRONG_INPUT -3
#define CANT_SOLVE -4
#define NOT_PRIME -5

int check_for_prime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return NOT_PRIME;
        }
    }
    return EXIT_SUCCESS;
}

int enter_array(int *arr, size_t len)
{
    int rc;
    printf("Input your items: ");
    for (size_t i = 0; i < len; i++)
    {
        rc = scanf("%d", &arr[i]);
        if (rc != EXPECTED_SCANF_RESULT)
        {
            printf("Wrong input\n");
            return WRONG_INPUT;
        }
    }
    return EXIT_SUCCESS;
}

int add_to_arr(int *arr, size_t len, int *res, size_t *count)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] > 1)
        {
            if (check_for_prime(arr[i]) == EXIT_SUCCESS)
            {
                res[*count] = arr[i];
                *count++;
            }
        }
    }
    if (*count == 0)
    {
        printf("You must enter more then zero prime numbers\n");
        return CANT_SOLVE;
    }
    return EXIT_SUCCESS;
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
    if (len > MAX_LEN_OF_ARR)
    {
        printf("Length of array must be under or equal ten\n");
        return TOO_BIG_VALUE;
    }

    int arr[MAX_LEN_OF_ARR];
    if (enter_array(arr, len) != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }

    int res[MAX_LEN_OF_ARR];
    size_t count = 0;
    if (add_to_arr(arr, len, res, &count) == EXIT_SUCCESS)
    {
        printf("Your prime numbers is ");
        for (size_t i = 0; i < count; i++)
        {
            printf("%d ", res[i]);
        }
        printf("\n");
    }
    else
    {
        return CANT_SOLVE;
    }

    return EXIT_SUCCESS;
}
