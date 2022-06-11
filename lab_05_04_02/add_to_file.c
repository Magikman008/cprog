#include "add_to_file.h"

void insert_to_array(good_t *goods, size_t count, good_t good)
{
    size_t cur = 0;

    while (goods[cur].amount > good.amount)
        cur++;

    while (goods[cur].number > good.number && goods[cur].amount == good.amount)
        cur++;

    good_t temp1 = goods[cur];
    goods[cur] = good;
    cur++;
    good_t temp2;

    while (cur < count)
    {
        temp2 = goods[cur];
        goods[cur] = temp1;
        temp1 = temp2;
        cur++;
    }
}
