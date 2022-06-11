#include "translator.h"

#define EXPECTED_SCANF_RESULT 1

int tb(FILE *in, FILE *out, char (*formats)[FORMAT_LEN], int number)
{
    short int ok = 1;
    void *a = NULL;
    a = (void *)malloc(sizeof(int));

    while (ok == 1)
    {
        for (int i = 0; i < number; i++)
        {
            if (strcmp(formats[i], "d") == 0)
            {
                a = (void *)realloc(a, sizeof(int));

                if (fscanf(in, "%d", (int *)a) != EXPECTED_SCANF_RESULT)
                    ok = 0;
                else
                    fwrite(&(*(int*)a), sizeof(int), 1, out);
            }

            if (strcmp(formats[i], "s") == 0)
            {
                a = (void *)realloc(a, MAX_LEN_STR);

                if (fscanf(in, "%s", (char *)a) != EXPECTED_SCANF_RESULT)
                    ok = 0;
                else
                {
                    char tmp[MAX_LEN_STR];
                    strcpy(tmp, a);
                    fwrite(&tmp, 1, MAX_LEN_STR, out);
                }
            }

            if (strcmp(formats[i], "f") == 0)
            {
                a = (void *)realloc(a, sizeof(float));

                if (fscanf(in, "%f", (float *)a) != EXPECTED_SCANF_RESULT)
                    ok = 0;
                else
                    fwrite(&a, sizeof(float), 1, out);
            }
        }
    }

    return EXIT_SUCCESS;
}

int bt(FILE *in, FILE *out, char (*formats)[FORMAT_LEN], int number)
{
    short int ok = 1;
    void *a = NULL;
    a = (void *)malloc(sizeof(int));

    while (ok == 1)
    {
        for (int i = 0; i < number; i++)
        {
            if (strcmp(formats[i], "d") == 0)
            {
                a = (void *)realloc(a, sizeof(int));

                if (fread(a, sizeof(int), 1, in) != EXPECTED_SCANF_RESULT)
                    ok = 0;
                else
                    fprintf(out, "%d\n", (*(int *)a));
            }

            if (strcmp(formats[i], "s") == 0)
            {
                a = (void *)realloc(a, MAX_LEN_STR);

                if (fread(a, 1, MAX_LEN_STR, in) != MAX_LEN_STR)
                    ok = 0;
                else
                    fprintf(out, "%s\n", (char *)a);
            }

            if (strcmp(formats[i], "f") == 0)
            {
                a = (void *)realloc(a, sizeof(float));

                if (fread(a, sizeof(float), 1, in) != EXPECTED_SCANF_RESULT)
                    ok = 0;
                else
                    fprintf(out, "%f\n", (*(float *)a));
            }
        }
    }

    return EXIT_SUCCESS;
}