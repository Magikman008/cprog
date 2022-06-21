#include "translator.h"
#include "case.h"

void split_format(char (*formats)[FORMAT_LEN], char *format, int *number_formats)
{
    char tmp[FORMAT_LEN];
    int cur = 0;

    for (size_t i = 0; format[i] != '\0'; i++)
    {
        if (isspace(format[i]))
        {
            tmp[cur] = '\0';
            strcpy(formats[*number_formats], tmp);
            (*number_formats)++;
            cur = 0;
        }
        else
        {
            tmp[cur] = format[i];
            cur++;
        }
    }

    tmp[cur] = '\0';
    strcpy(formats[*number_formats], tmp);
    number_formats++;
}

void case_t2b(FILE *in_file, FILE *out_file, char *format)
{
    char formats[MAX_FORMATS][FORMAT_LEN];
    int number_formats = 0;

    split_format(formats, format, &number_formats);
    text_to_bin(in_file, out_file, formats, number_formats);
}

void case_b2t(FILE *in_file, FILE *out_file, char *format)
{
    char formats[MAX_FORMATS][FORMAT_LEN];
    int number_formats = 0;

    split_format(formats, format, &number_formats);
    bin_to_text(in_file, out_file, formats, number_formats);
}
