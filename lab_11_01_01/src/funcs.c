#include "../inc/funcs.h"

size_t cchar(char *const dst, const char chr, size_t *const curlen, const size_t max)
{
    if (*curlen < max - 1)
        dst[(*curlen)++] = chr;

    return 1;
}

size_t cstring(char *const dst, char *const src, size_t *const curlen, const size_t max)
{
    int i = 0;
    size_t added = 0;

    while (src[i] != '\0')
    {
        added += cchar(dst, src[i], curlen, max);
        i++;
    }

    return added;
}

char *my_itoa(long long value, char *const string, const int radix)
{
    char *chars = "0123456789abcdef";
    size_t len = 0;
    long long value_backup = value;

    if (value == 0)
        string[len++] = '0';

    if (value < 0)
        value *= -1;

    while (value != 0)
    {
        string[len++] = chars[value % radix];
        value /= radix;
    }

    if (value_backup < 0)
        string[len++] = '-';

    for (size_t i = 0; i < len / 2; i++)
    {
        char temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    }

    string[len] = '\0';

    return string;
}

char *my_strncpy(char *const destptr, const char *srcptr, const size_t num)
{
    size_t len = 0;

    while (*srcptr != '\0' && len < num)
    {
        destptr[len] = srcptr[len];
        len++;
    }

    destptr[len] = '\0';

    return destptr;
}

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
    if (n != 0 && s == NULL)
        return -1;

    char *temp = calloc(n, sizeof(char));

    if (temp == NULL)
        return 0;

    size_t len = 0;

    va_list args;
    va_start(args, format);

    char *tempstr;
    char str[100];
    int toreturn = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    toreturn += cchar(temp, va_arg(args, int), &len, n);
                    break;
                case 'i':
                case 'd':
                    my_itoa(va_arg(args, int), str, 10);
                    toreturn += cstring(temp, str, &len, n);
                    break;
                case 's':
                    tempstr = va_arg(args, char *);
                    toreturn += cstring(temp, tempstr, &len, n);
                    break;
                case 'x':
                    my_itoa(va_arg(args, unsigned int), str, 16);
                    toreturn += cstring(temp, str, &len, n);
                    break;
                case 'o':
                    my_itoa(va_arg(args, unsigned int), str, 8);
                    toreturn += cstring(temp, str, &len, n);
                    break;
                default:
                    toreturn += cchar(temp, '%', &len, n);
                    break;
            }
        }
        else
            toreturn += cchar(temp, *format, &len, n);
        format++;
    }

    temp[len] = '\0';
    va_end(args);
    if (!s || n == 0)
    {
        free(temp);
        return len;
    }
    my_strncpy(s, temp, len);
    free(temp);

    return toreturn;
}
