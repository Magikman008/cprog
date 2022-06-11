#include "translator.h"
#include <ctype.h>

#define MAX_FORMATS 20

#define ERROR_WRONG_ARGS 53
#define ERROR_NO_FILE -2

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "t2b") != 0 && strcmp(argv[1], "b2t") != 0 && argc < 4)
        return ERROR_WRONG_ARGS;

    FILE *in;
    FILE *out;

    if (strcmp(argv[1], "t2b") == 0)
    {
        in = fopen(argv[2], "r");
        out = fopen(argv[3], "wb");

        if (!in)
        {
            return ERROR_NO_FILE;
        }

        char formats[MAX_FORMATS][FORMAT_LEN];
        int number_formats = 0;
        char tmp[FORMAT_LEN];
        int cur = 0;
        for (size_t i = 0; argv[4][i] != '\0'; i++)
        {
            if (isspace(argv[4][i]))
            {
                tmp[cur] = '\0';
                strcpy(formats[number_formats], tmp);
                number_formats++;
                cur = 0;
            }
            else
            {
                tmp[cur] = argv[4][i];
                cur++;
            }
        }
        tmp[cur] = '\0';
        strcpy(formats[number_formats], tmp);
        number_formats++;

        tb(in, out, formats, number_formats);
        fclose(in);
        fclose(out);
    }

    if (strcmp(argv[1], "b2t") == 0)
    {
        in = fopen(argv[2], "rb");
        out = fopen(argv[3], "w");

        if (!in)
        {
            return ERROR_NO_FILE;
        }

char formats[MAX_FORMATS][FORMAT_LEN];
        int number_formats = 0;
        char tmp[FORMAT_LEN];
        int cur = 0;
        for (size_t i = 0; argv[4][i] != '\0'; i++)
        {
            if (isspace(argv[4][i]))
            {
                tmp[cur] = '\0';
                strcpy(formats[number_formats], tmp);
                number_formats++;
                cur = 0;
            }
            else
            {
                tmp[cur] = argv[4][i];
                cur++;
            }
        }
        tmp[cur] = '\0';
        strcpy(formats[number_formats], tmp);
        number_formats++;

        bt(in, out, formats, number_formats);
        fclose(in);
        fclose(out);
    }

    return EXIT_SUCCESS;
}