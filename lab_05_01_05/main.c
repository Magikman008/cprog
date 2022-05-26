#include "process_file.h"
#include <stdlib.h>

int main(void)
{
    int count = 0;
    int rc = process(stdin, &count);

    if (rc != EXIT_SUCCESS)
        return rc;

    printf("%d", count);

    return EXIT_SUCCESS;
}
