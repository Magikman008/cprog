#include "../inc/header.h"
#include "../inc/funcs.h"

int main(int argc, char **argv)
{
    FILE *f;
    if (argc == 2)
        f = fopen(argv[1], "r");
    else
        return EXIT_FAILURE;

    node_t *head = malloc(sizeof(node_t));

    head->next = NULL;
    head->prev = NULL;

    if (fscanf(f, "%d", &head->value) != 1)
    {
        free_list(head);
        return EXIT_FAILURE;
    }

    int temp;
    while (fscanf(f, "%d", &temp) == 1)
        push(&head, temp);

    reduce(head);

    if (fclose(f))
    {
        free_list(head);
        return EXIT_FAILURE;
    }

    f = fopen("out.txt", "w");
    print_list(head, f);

    free_list(head);

    if (fclose(f))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
