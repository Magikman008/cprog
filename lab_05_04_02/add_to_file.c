#include "add_to_file.h"

void insert_to_array(good_t *goods, size_t count, good_t good)
{
    printf("%ld\n", count);
    size_t cur = count - 1;
    printf("%" PRIu32 "\n", goods[cur].amount);
    while (goods[cur].amount < good.amount)
    {
        puts("1ok");
        goods[cur + 1] = goods[cur];
        cur--;
    }

    while (goods[cur].number < good.number && goods[cur].amount == good.amount)
    {
        puts("2ok");
        goods[cur + 1] = goods[cur];
        cur--;
    }

    goods[cur + 1] = good;
}
