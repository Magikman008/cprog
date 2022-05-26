#include "process_sequence.h"
#include <stdlib.h>

int main(void)
{
    setbuf(stdout, NULL);
    int count = 0;
    int rc = process(stdin, &count);

    if (rc != EXIT_SUCCESS)
        return rc;

    printf("%d\n", count);

    return EXIT_SUCCESS;
}
