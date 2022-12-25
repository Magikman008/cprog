#include "../inc/header.h"
#include "../inc/funcs.h"

// вариант 5, ввод и хранение 1, задание 1 минимум, задание 2 ряды, вывод 1

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
        return EXIT_FAILURE;

    int temp;
    while (fscanf(f, "%d", &temp) == 1)
        push(&head, temp);

    print_list(head, stdout);
    reduce(head);
    fclose(f);
    f = fopen("out.txt", "w");
    print_list(head, f);
    fclose(f);
    // free_list(head);

    return EXIT_SUCCESS;
}
