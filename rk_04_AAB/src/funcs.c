#include "../inc/funcs.h"

void push(node_t **const head, const int value)
{
    node_t *temp = calloc(1, sizeof(node_t));

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

void print_list(node_t *const head, FILE *const f)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        fprintf(f, "%d ", temp->value);
        temp = temp->next;
    }
    fprintf(f, "\n");
}

void reduce(node_t *const head)
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

void free_list(node_t *const head)
{
    node_t *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
        free(temp->prev);
    }
    free(temp);
}
