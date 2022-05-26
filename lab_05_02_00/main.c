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

    printf("%f\n", average);
    fclose(f);

    f = fopen(argv[1], "r");
    float nearest;
    rc = find_nearest(f, average, &nearest);

    if (rc != EXIT_SUCCESS)
        return rc;

    printf("%f\n", nearest);
    fclose(f);

    return EXIT_SUCCESS;
}
