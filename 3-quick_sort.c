#include "sort.h"
/**
 *
 *
 *
 */
void quick_sort_recursion(int *array, int start, int end)
{
    int position_index;

    position_index = partition_array(array, start, end);
    quick_sort_recursion(array, start, position_index - 1);
    quick_sort_recursion(array, position_index + 1, end);
}

int partition_array(int *array, int start, int end)
{
    
}
void quick_sort(int *array, size_t size)
{
    size_t i = 0;
    size_t j = -1;
    size_t pivot = size - 1;
    int tmp;

    if (size < 2)
        return;
    while (i <= pivot)
    {
        if (array[i] <= array[pivot])
        {
            j++;
            if (i != j)
            {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
                print_array(array, size);
            }
        }
        i++;
    }
}