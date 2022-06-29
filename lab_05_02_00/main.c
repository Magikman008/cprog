#include "process_file.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return ERROR_NO_FILE;

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return ERROR_EMPTY_FILE;

    float average;
    int rc = find_average(f, &average);

    if (rc != EXIT_SUCCESS)
        return rc;

    fseek(f, 0, SEEK_SET);

    float nearest;
    rc = find_nearest(f, average, &nearest);

    if (rc != EXIT_SUCCESS)
        return rc;

    printf("%f\n", nearest);

    if (fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    return EXIT_SUCCESS;
}
