#include "../inc/funcs.h"

int count_elems(FILE *f, size_t *count)
{
    int rc = EXPECTED_SCANF;

    while (rc == EXPECTED_SCANF)
    {
        rc = 0;
        char *s;
        float temp = 0;
        size_t size = 1;
        s = (char *)malloc(sizeof(char));

        if (getline(&s, &size, f) > 0)
            rc++;

        if (fscanf(f, "%f\n", &temp) == 1)
            rc++;
        if (fscanf(f, "%f\n", &temp) == 1)
            rc++;

        if (rc == EXPECTED_SCANF)
            (*count)++;

        free(s);
    }

    if (*count == 0)
        return ERROR_NO_ITEMS;

    if (rc != 0)
        return ERROR_BAD_FILE;

    return EXIT_SUCCESS;
}

void read_array(FILE *f, item_t *items, const int count)
{
    for (int i = 0; i < count; i++)
    {
        char *s;
        size_t size = 1;
        s = (char *)malloc(sizeof(char));
        getline(&s, &size, f);
        s[strlen(s) - 1] = '\0';
        items[i].name = s;
        fscanf(f, "%f\n", &items[i].weight);
        fscanf(f, "%f\n", &items[i].volume);
    }
}

// void print_array(item_t *items, const int count)
// {
//     for (int i = 0; i < count; i++)
//         printf("%s\n%f\n%f\n", items[i].name, items[i].weight, items[i].volume);
// }

int print_filtered_array(item_t *items, const int count, char *string)
{
    for (int i = 0; i < count; i++)
        if (strstr(items[i].name, string) == items[i].name)
            printf("%s\n%f\n%f\n", items[i].name, items[i].weight, items[i].volume);

    return EXIT_SUCCESS;
}

void sort_array(item_t *items, const int count)
{
    for (int i = count - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (items[j].volume * items[j].weight > items[j + 1].volume * items[j + 1].weight)
            {
                item_t temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void free_items(item_t *items, size_t count)
{
    for (size_t i = 0; i < count; i++)
        free(items[i].name);

    free(items);
}
