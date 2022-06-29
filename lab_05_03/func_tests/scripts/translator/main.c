#include "translator.h"
#include "case.h"

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "t2b") != 0 && strcmp(argv[1], "b2t") != 0 && argc < 4)
        return ERROR_WRONG_ARGS;

    FILE *in;
    FILE *out;
    in = fopen(argv[2], "r");
    out = fopen(argv[3], "wb");

    if (!in)
        return ERROR_NO_FILE;

    if (strcmp(argv[1], "t2b") == 0)
    {
        case_t2b(in, out, argv[4]);
        fclose(in);
        fclose(out);
    }

    if (strcmp(argv[1], "b2t") == 0)
    {
        case_b2t(in, out, argv[4]);
        fclose(in);
        fclose(out);
    }

    return EXIT_SUCCESS;
}
