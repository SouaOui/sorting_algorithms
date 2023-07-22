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
                return;
            }
            else
            {
                target = current;
                tmp = current->next;
                current = previous;
                while (previous)
                {
                    if (n < previous->n && tmp)
                    {
                        printf("*%d/\n", previous->n);
                        /* swap any element deep 3+ in list*/
                        tmp->prev = previous;
                        previous->next = tmp;
                        /* use to change previous->prev*/
                        /*tmp = previous; tmp->prev = x;*/
                        tmp = previous;
                        previous = previous->prev;
                        if (previous)
                            continue;
                    }
                    else if (n < previous->n && !tmp)
                    {
                        printf("+%d/\n", previous->n);
                        previous->prev->next = target;
                        target->prev = previous->prev;
                        previous->next = NULL;
                        previous->prev = target;
                        print_list(*list);
                        continue;
                    }
                    printf("_ \n");
                    /*
                    comparaison stop we found
                    previous is less than current
                    */
                    tmp->prev = target;
                    if (previous)
                        previous->next = target;
                    target->next = tmp;
                    target->prev = previous;
                    if (!previous)
                        *list = target;
                    break;
                }

                print_list(*list);
                printf("3- ");
            }
        }
        else
        {
            print_list(*list);
            printf("0- ");
        }
        printf("\n");
        previous = current;
        current = current->next;
    }
}
