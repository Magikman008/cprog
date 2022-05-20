#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_OF_STR 257

char *my_strpbrk(const char *const string, const char *const keys)
{
    for (size_t i = 0; string[i] != '\0'; i++)
        for (size_t j = 0; keys[j] != '\0'; j++)
            if (string[i] == keys[j])
                return (char *)string + i;

    return NULL;
}

size_t my_strspn(const char *const string, const char *const keys)
{
    size_t maximum = 0;
    size_t cur_max = 0;
    int flag = 0;

    for (size_t i = 0; string[i] != '\0' && flag == 0; i++)
    {
        cur_max = 0;
        for (size_t j = 0; keys[j] != '\0'; j++)
            if (string[i] == keys[j])
            {
                cur_max++;
            }

        if (cur_max != 0)
            maximum++;
        else
            return maximum;
    }

    return maximum;
}

size_t my_strcspn(const char *const string, const char *const keys)
{
    size_t before = 0;

    for (size_t i = 0; string[i] != '\0'; i++)
    {
        for (size_t j = 0; keys[j] != '\0'; j++)
            if (string[i] == keys[j])
                return before;

        before++;
    }

    return before;
}

char *my_strchr(const char *const string, const int symbol)
{
    size_t i;
    for (i = 0; string[i] != '\0'; i++)
        if (string[i] == symbol)
            return (char *)string + i;

    if (symbol == '\0')
        return (char *)(string + i);

    return NULL;
}

char *my_strrchr(const char *const string, const int symbol)
{
    char *result = NULL;
    size_t i;
    for (i = 0; string[i] != '\0'; i++)
        if (string[i] == symbol)
            result = (char *)string + i;

    if (symbol == '\0')
        return (char *)(string + i);

    return result;
}

int main(void)
{
    char *test1[5][2] = {
        { "Disrdf", "htio" },
        { "Disrdf", "hto" },
        { "", "" },
        { "0123456789", "012" },
        { "0123456789", "fhjd4" } };

    struct person
    {
        char first[MAX_LEN_OF_STR];
        int second;
    };

    struct person test2[3] = {
        { "01234564789", '4' },
        { "012356789", '4' },
        { "", '4' } };

    size_t incorrect = 0;

    for (size_t i = 0; i < 5; i++)
        if (my_strpbrk(test1[i][0], test1[i][1]) != strpbrk(test1[i][0], test1[i][1]))
            incorrect++;

    for (size_t i = 0; i < 5; i++)
        if (my_strspn(test1[i][0], test1[i][1]) != strspn(test1[i][0], test1[i][1]))
            incorrect++;

    for (size_t i = 0; i < 5; i++)
        if (my_strcspn(test1[i][0], test1[i][1]) != strcspn(test1[i][0], test1[i][1]))
            incorrect++;

    for (size_t i = 0; i < 3; i++)
        if (my_strchr(test2[i].first, test2[i].second) != strchr(test2[i].first, test2[i].second))
            incorrect++;

    for (size_t i = 0; i < 3; i++)
        if (my_strrchr(test2[i].first, test2[i].second) != strrchr(test2[i].first, test2[i].second))
            incorrect++;

    printf("%ld\n", incorrect);

    return incorrect ? EXIT_FAILURE : EXIT_SUCCESS;
}