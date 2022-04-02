#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN_OF_ARR 20
#define EXPECTED_SCANF_RESULT 1
#define TOO_BIG_VALUE -1
#define TOO_LITTLE_VALUE -2
#define WRONG_INPUT -3
#define CANT_SOLVE -4

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

void insert(int *arr, size_t len, size_t cur_i)
{
    for (size_t i = len - 1; i > cur_i; i--)
    {
        arr[i] = arr[i - 1];
    }
}

void check_arr(int *arr, size_t *len)
{
    size_t i = 0;
    int prev_f = 0;
    int cur_f = 0;
    int temp;
    while (i < *len)
    {
        if (arr[i] % 3 == 0)
        {
            insert(arr, *len + 1, i);
            *len = *len + 1;
            arr[i + 1] = cur_f;
            i += 2;

            if (cur_f == 0 && prev_f == 0)
            {
                cur_f = 1;
            }
            else
            {
                temp = cur_f;
                cur_f += prev_f;
                prev_f = temp;
            }
        }
        else
        {
            i += 1;
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

    check_arr(arr, &len);
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
