#include "add_to_file.h"

void insert_to_array(good_t *goods, size_t count, good_t good)
{
    int cur = count - 1;

    while (cur > -1 && (goods[cur].amount < good.amount || (goods[cur].number < good.number && goods[cur].amount == good.amount)))
    {
        goods[cur + 1] = goods[cur];
        cur--;
    }

    goods[cur + 1] = good;
}
