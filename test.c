void main()
{
    while (1)
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
        /*
        19, 48, 99, 71, 13, 52, 96, 73, 86, 7
        7, 13, 19, 48, 52, 71, 73, 86, 96, 99
        */
    }
}
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
                        current = previous->next;
                        if (!previous)
                            *list = current;
                        print_list(*list);
                        printf(".c%d .p%d\n", current->n, previous->n);
                    }
                    else
                    {
                        break;
                    }
                }
