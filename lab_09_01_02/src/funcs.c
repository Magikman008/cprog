#include "../inc/funcs.h"

int count_elems(FILE *f, size_t *count)
{
    int rc = EXPECTED_SCANF;

    while (rc == EXPECTED_SCANF)
    {
        rc = 0;
        char *s;
        double temp1 = 0;
        double temp2 = 0;
        size_t size = 1;
        s = (char *)malloc(sizeof(char));

        if (NULL == s)
            return ERROR_MALLOC;

        if (getline(&s, &size, f) > 0)
            rc++;

        if (fscanf(f, "%lf\n", &temp1) == 1)
            rc++;

        if (fscanf(f, "%lf\n", &temp2) == 1)
            rc++;

        if (rc == EXPECTED_SCANF)
        {
            (*count)++;
            if (temp1 < 10e-4 || temp2 < 10e-4)
            {
                free(s);
                return ERROR_ZERO;
            }
        }

        free(s);
    }

    if (*count == 0)
        return ERROR_NO_ITEMS;

    if (rc != 0)
        return ERROR_BAD_FILE;

    return EXIT_SUCCESS;
}

int read_array(const char *const file, item_t **items, size_t *count)
{
    FILE *src;

    if (!(src = fopen(file, "r")))
        return ERROR_FILE_OPEN;

    int rc = count_elems(src, count);

    if (rc)
    {
        if (fclose(src))
            return ERROR_FILE_CLOSE;

        return rc;
    }

    *items = (item_t *)malloc(sizeof(item_t) * *count);

    if (NULL == *items)
        return ERROR_MALLOC;

    rewind(src);

    for (size_t i = 0; i < *count; i++)
    {
        char *s;
        size_t size = 1;
        s = (char *)malloc(sizeof(char));

        if (NULL == s)
            return ERROR_MALLOC;

        getline(&s, &size, src);
        s[strlen(s) - 1] = '\0';
        (*items)[i].name = s;
        fscanf(src, "%lf\n", &((*items)[i].weight));
        fscanf(src, "%lf\n", &((*items)[i].volume));
    }

    if (fclose(src))
    {
        free_items(*items, *count);
        return ERROR_FILE_CLOSE;
    }

    return EXIT_SUCCESS;
}

void print_array(const item_t *const items, const size_t count)
{
    for (size_t i = 0; i < count; i++)
        printf("%s\n%f\n%f\n", items[i].name, items[i].weight, items[i].volume);
}

item_t *filter_array(item_t *items, size_t *count, const char *string)
{
    size_t temp_count = 0;

    for (size_t i = 0; i < *count; i++)
        if (strstr(items[i].name, string) == items[i].name)
            temp_count++;

    item_t *temp_items = (item_t *)malloc(sizeof(item_t) * temp_count);

    if (NULL == temp_items)
        return NULL;

    for (size_t i = 0, j = 0; i < *count; i++)
        if (strstr(items[i].name, string) == items[i].name)
            temp_items[j++] = items[i];
        else
            free(items[i].name);

    *count = temp_count;
    free(items);

    return temp_items;
}

void sort_array(item_t *items, const int count)
{
    for (int i = count - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (items[j].weight / items[j].volume > items[j + 1].weight / items[j + 1].volume)
            {
                item_t temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void free_items(item_t *items, const size_t count)
{
    for (size_t i = 0; i < count; i++)
        free(items[i].name);

    free(items);
}
