#include "sort_file.h"
#include "print_file.h"
#include <stdlib.h>

#define EXPECTED_SCANF_RESULT 1

int get_number_by_pos(FILE *f, int pos, int *num)
{
    int cur;
    int count = 0;

    while (count <= pos)
    {
        count++;

        if (fread(&cur, sizeof(int), 1, f) != EXPECTED_SCANF_RESULT)
            return ERROR_WRONG_POS;
    }

    *num = cur;

    return EXIT_SUCCESS;
}

int put_number_by_pos(FILE *f, int pos, int number)
{
    int cur;
    int count = 1;

    while (count <= pos)
    {
        count++;

        if (fread(&cur, sizeof(int), 1, f) != EXPECTED_SCANF_RESULT)
            return ERROR_WRONG_POS;
    }

    if (fwrite(&number, sizeof(int), 1, f) != 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int sort(char *file, size_t count)
{
    int num1 = 0;
    int num2 = 0;
    FILE *f;

    for (size_t i = 0; i < count; i++)
        for (size_t j = i; j < count; j++)
        {
            f = fopen(file, "rb");
            get_number_by_pos(f, i, &num1);
            fclose(f);
            f = fopen(file, "rb");
            get_number_by_pos(f, j, &num2);
            fclose(f);

            if (num1 > num2)
            {
                f = fopen(file, "rb+");
                put_number_by_pos(f, i, num2);
                fclose(f);
                f = fopen(file, "rb+");
                put_number_by_pos(f, j, num1);
                fclose(f);
            }
        }

    return EXIT_SUCCESS;
}