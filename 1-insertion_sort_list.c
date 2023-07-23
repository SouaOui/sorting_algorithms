#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *previous, *tmp;
    int n;

    /* check empty list and only one element in list */
    if (!*list || !(*list)->next)
        return;

    previous = *list;
    current = previous->next;
    while (current)
    {
        n = current->n;
        tmp = current->next;
        if (previous)
            printf("\n- cur: %d - pr: %d\n", current->n, previous->n);
        print_list(*list);
        if (n < previous->n)
        {
            if (!current->next && !previous->prev)
            {
                /*
                swap first element
                in list that have only 2 elem
                */
                previous->next = NULL;
                previous->prev = current;
                current->next = previous;
                current->prev = NULL;
                *list = current;
                print_list(*list);
                printf("1- ");
                return;
            }
            else if (!previous->prev)
            {
                /*
                the first element need to swap
                in list that have more than 2 elem
                */
                previous->next = current->next;
                previous->prev = current;
                current->next = previous;
                current->prev = NULL;
                *list = current;
                print_list(*list);
                printf("2- ");
            }
            else
            {
                while (previous)
                {
                    if (n < previous->n)
                    {
                        printf("+%d/\n", previous->n);
                        print_list(*list);
                        if (previous->prev)
                            previous->prev->next = current;
                        current->prev = previous->prev;
                        previous->next = current->next;
                        previous->prev = current;
                        if (current->next)
                            current->next->prev = previous;
                        current->next = previous;
                        previous = current->prev;
                        if (!previous)
                            *list = current;
                        print_list(*list);
                        if (previous)
                            printf(".c%d .p%d\n", current->n, previous->n);
                        printf("3- ");
                    }
                    else
                        break;
                }
            }
        }
        else
        {
            print_list(*list);
            printf("0- ");
        }
        printf("\n");

        printf("axx\n");
        if (previous)
            printf("..c%d ..p%d\n", current->n, previous->n);
        current = tmp;
        printf("axxx\n");
        if(!current)
            break;
        previous = current->prev;
        printf("ax\n");
    }
    printf("a\n");
}
