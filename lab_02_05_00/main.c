#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define TOO_BIG_VALUE -1
#define TOO_LITTLE_VALUE -2
#define WRONG_INPUT -3

int enter_array(int *s, int *e)
{
    int rc;
    printf("Input your items: ");
    while (s < e)
    {
        rc = scanf("%d", s);
        if (rc != EXPECTED_SCANF_RESULT)
        {
            printf("Wrong input\n");
            return WRONG_INPUT;
        }
        s++;
    }
    return EXIT_SUCCESS;
}

int check_arr(int *s, int *e)
{
    int count = 0;
    for (int *i = s; i < e; i++)
    {
        int cur_count = 0;
        for (int *j = i + 1; j < e; j++)
        {
            if (*i == *j) 
            {
                cur_count++;
            }
        }
        if (cur_count == 0)
            count++;
    }
    return count;
}

int enter_len(size_t *len)
{
    printf("Input length of array: ");
    int rc = scanf("%zu", len);
    if (rc != EXPECTED_SCANF_RESULT)
    {
        printf("Wrong input\n");
        return WRONG_INPUT;
    }
    if (*len < 1)
    {
        printf("Length of array must be over zero\n");
        return TOO_LITTLE_VALUE;
    }
    if (*len > MAX_LEN_OF_ARR)
    {
        printf("Length of array must be under or equal ten\n");
        return TOO_BIG_VALUE;
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    setbuf(stdout, NULL);
    int arr[MAX_LEN_OF_ARR];
    size_t len;
    int rc;
    if ((rc = enter_len(&len)) != EXIT_SUCCESS)
        return rc;
    if ((rc = enter_array(arr, arr + len)) != EXIT_SUCCESS)
        return rc;
    printf("Number of unique numbers %d\n", check_arr(arr, arr + len));
    return EXIT_SUCCESS;
}