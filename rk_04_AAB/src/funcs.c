#include "../inc/funcs.h"

void push(node_t **head, int value)
{
    node_t *temp = malloc(sizeof(node_t));

    if (temp == NULL)
        exit(ERROR_OVERFLOW);

    temp->next = NULL;
    temp->value = value;

    node_t *in = *head;
    while (in->next != NULL)
        in = in->next;

    temp->prev = in;
    in->next = temp;
}

void print_list(node_t *head, FILE *f)
{
    node_t *temp = head;
    while (temp->next != NULL)
    {
        fprintf(f, "%d ", temp->value);
        temp = temp->next;
    }

    fprintf(f, "%d\n", temp->value);
}

void reduce(node_t *head)
{
    node_t *temp = head;

    while (temp->next != NULL)
    {
        node_t *tofree = temp->next;
        temp->value += temp->next->value;
        temp->next = temp->next->next;
        free(tofree);
        if (temp->next != NULL)
        {
            temp->next->prev = temp;
            temp = temp->next;
        }
    }
}

void free_list(node_t *head)
{
    node_t *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
        free(temp->prev);
        print_list(temp, stdout);
    }
}
