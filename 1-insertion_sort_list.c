#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *previous, *tmp, *target;
    int n;

    /* check empty list and only one element in list */
    if (!*list || !(*list)->next)
        return;

    previous = *list;
    current = previous->next;
    while (current)
    {
        n = current->n;
        printf("- current: %d - previous: %d - ", current->n, previous->n);
        print_list(*list);
        if (n < previous->n)
        {
            if (!current->next && !previous->prev)
            {
                printf("- %d < %d - Case1: ", n, previous->n);
                /*
                swap first element
                in list that have only 2 elem
                */
                previous->next = NULL;
                previous->prev = current;
                current->next = previous;
                current->prev = NULL;
                *list = current;
                return;
            }
            else if (!previous->prev)
            {
                printf("- %d < %d - Case2: ", n, previous->n);
                /*
                the first element need to swap
                in list that have more than 2 elem
                */
                previous->next = current->next;
                previous->prev = current;
                current->next = previous;
                current->prev = NULL;
                *list = current;
                return;
            }
            else
            {
                printf("- %d < %d - Case3: ", n, previous->n);
                target = current;
                tmp = current->next;
                current = previous;
                while (previous)
                {
                    if (n < previous->n)
                    {
                        /* swap any element deep 3+ in list*/
                        tmp->prev = previous;
                        previous->next = tmp;
                        /* use to change previous->prev*/
                        /*tmp = previous; tmp->prev = x;*/
                        tmp = previous;
                        previous = previous->prev;
                    }
                    else
                    {
                        /*
                        comparaison stop we found
                        previous is less than current
                        */
                        tmp->prev = target;
                        previous->next = target;
                        target->next = tmp;
                        target->prev = previous;
                        break;
                    }
                }
            }
        }
        else
        {
            printf("- %d < %d - Case0: ", n, previous->n);
        }
        print_list(*list);
        previous = current;
        current = current->next;
    }
}
