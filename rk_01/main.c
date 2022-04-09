#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_ARR 10

void input_arr(int *arr, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		scanf("%d", (arr + i));
	}	
}

void twenty_fourty_eight(int *degrees, int *doings, size_t *ldeg, size_t ldo)
{
	for (size_t i = 0; i < ldo; i++)
	{
		if (*(doings + i) == -1)
		{
			size_t j = 0;
			while (j < *ldeg - 1)
			{
				if (*(degrees + j) == *(degrees + j + 1))
				{	
					*(degrees + j) = *(degrees + j) + *(degrees + j + 1);			
					for (size_t c = j + 1; c < *ldeg - 1; c++)
					{
						*(degrees + c) = *(degrees + c + 1);
					}
					*ldeg -= 1;
				}
				j++;
			}
		}
		if (*(doings + i) == 1)
		{
			size_t j = *ldeg - 1;
			while (j > 0)
			{
				if (*(degrees + j) == *(degrees + j - 1))
				{	
					*(degrees + j) = *(degrees + j) + *(degrees + j - 1);			
					for (size_t c = j + 1; c > 0; c--)
					{
						*(degrees + c) = *(degrees + c - 1);
					}
					*ldeg -= 1;
				}
				j--;
			}
		}
	}
}

void show(int *degrees, size_t ldeg)
{
	for (size_t i = 0; i < ldeg; i++)
	{
		printf("%d ", *(degrees + i));
	}
	puts("");
}

int main(void)
{
    size_t len_degrees_arr;
    puts("Input number of numbers: ");
    scanf("%zu",&len_degrees_arr);
    int degrees[MAX_LEN_ARR];
    int doings[MAX_LEN_ARR];
    puts("Input your items: ");
    input_arr(degrees, len_degrees_arr);
    size_t len_doings_arr;
    puts("Input number of doings: ");
    scanf("%zu",&len_doings_arr);
    puts("Input your doings: ");
    input_arr(doings, len_doings_arr);
    puts("done");
    twenty_fourty_eight(degrees, doings, &len_degrees_arr, len_doings_arr);
    show(degrees, len_degrees_arr);
    return EXIT_SUCCESS;
    
}







//gcc -std=c99 -Wall -Werror -Wextra -Wpedantic main.c -o main.exe
