#include "sort.h"

void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i = 0;
    int j = 0, ii = 0;
    int tmp;

    while (gap <= size)
    {
        if (gap * 3 + 1 > size)
            break;
        gap = gap * 3 + 1;
    }
    for (gap = gap; gap > 1; gap = (gap - 1) / 3)
    {
        for (i = 0; i + gap < size; i++)
        {
            if (array[i + gap] < array[i])
            {
                for (j = i + gap, ii = i; j >= 0; j = j - gap, ii = ii - gap)
                {
                    if (array[j] < array[ii])
                    {
                        tmp = array[j + gap];
                        array[j + gap] = array[j];
                        array[j] = tmp;
                    }
                }
            }
        }
        print_array(array, size);
    }
    j = 0;
    ii = 0;
    i = 0;
    for (i = 1; i < size; i++)
    {
        if (array[i] < array[i - 1])
        {
            for (j = i - 1, ii = i; j >= 0; j--, ii--)
            {
                if (array[ii] < array[j])
                {
                    tmp = array[ii];
                    array[ii] = array[j];
                    array[j] = tmp;
                }
            }
        }
    }

    print_array(array, size);
}
