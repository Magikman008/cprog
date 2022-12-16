#include "../inc/funcs.h"

char *my_itoa(long long value, char *string, int radix)
{
    char *chars = "0123456789abcdef";
    size_t len = 0;
    long long value_backup = value;

    if (value < 0 && (radix == 16 || radix == 8))
    {
        value = 4294967295 + value + 1;
        value_backup *= -1;
    }
    else if (value < 0)
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

char *my_strncpy(char *destptr, const char *srcptr, size_t num)
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
    size_t len = 0;

    va_list args;
    va_start(args, format);

    char *tempstr;
    char str[100];
    int i = 0;
    int toreturn = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c':
                CCHAR(va_arg(args, int));
                break;
            case 'i': // целое со знаком
            case 'd': // целое со знаком
                my_itoa(va_arg(args, int), str, 10);
                CSTRING(str);
                break;
            case 's': // строка
                tempstr = va_arg(args, char *);
                CSTRING(tempstr);
                break;
            case 'x': // шеснадцатиричное без знака
                my_itoa(va_arg(args, int), str, 16);
                CSTRING(str);
                break;
            case 'o': // восьмеричное
                my_itoa(va_arg(args, int), str, 8);
                CSTRING(str);
                break;
            default:
                break;
            }
        }
        else
        {
            CCHAR(*format);
        }
        format++;
    }

    temp[len] = '\0';
    va_end(args);
    my_strncpy(s, temp, len);
    free(temp);

    return toreturn;
}
