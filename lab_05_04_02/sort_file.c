#include "sort_file.h"

int sort_file(good_t *goods, size_t count)
{
    for (size_t i = 0; i < count; i++)
        for (size_t j = i; j < count; j++)
        {
            if (goods[i].amount < goods[j].amount)
            {
                good_t temp = goods[i];
                goods[i] = goods[j];
                goods[j] = temp;
            }
            else if (goods[i].amount == goods[j].amount && goods[i].number < goods[j].number)
            {
                good_t temp = goods[i];
                goods[i] = goods[j];
                goods[j] = temp;
            }
        }

    return EXIT_SUCCESS;
}

int write_file(FILE *f, good_t *goods, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(f, "%s\n%s\n%u\n%u\n", goods[i].name, goods[i].manufac, goods[i].amount, goods[i].number);
    }
    return EXIT_SUCCESS;
}