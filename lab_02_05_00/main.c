#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define TOO_BIG_VALUE -1
#define TOO_LITTLE_VALUE -2
#define WRONG_INPUT -3

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

int check_arr(int *arr, size_t len)
{
    int count = 0;
    for (size_t i = 0; i < len; i++)
    {
        int cur_count = 0;
        for (size_t j = i + 1; j < len; j++)
        {
            if (*(arr + i) == *(arr + j)) 
            {
                cur_count++;
            }
        }
        if (cur_count == 0)
            count++;
    }
    return count;
}


int main(void)
{
    setbuf(stdout, NULL);
    int arr[MAX_LEN_OF_ARR];
    if (enter_array(arr, len) != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }
    printf("Number of unique numbers %d\n", check_arr(arr, len));
    return EXIT_SUCCESS;
}