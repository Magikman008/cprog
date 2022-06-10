#include "sort_file.h"

int sort_file(good_t *goods, size_t count)
{
    for (size_t i = 0; i < count; i++)
        for (size_t j = 0; j < count - 1; j++)
        {
            if (goods[j].amount < goods[j + 1].amount)
            {
                good_t temp = goods[j + 1];
                goods[j + 1] = goods[j];
                goods[j] = temp;
            }
            else if (goods[j].amount == goods[j + 1].amount && goods[j].number < goods[j + 1].number)
            {
                good_t temp = goods[j + 1];
                goods[j + 1] = goods[j];
                goods[j] = temp;
            }
        }

    return EXIT_SUCCESS;
}

int write_file(FILE *f, good_t *goods, size_t count)
{
    for (size_t i = 0; i < count; i++)
        fprintf(f, "%s%s%" SCNu32 "\n%" SCNu32 "\n", goods[i].name, goods[i].manufac, goods[i].amount, goods[i].number);

    return EXIT_SUCCESS;
}
