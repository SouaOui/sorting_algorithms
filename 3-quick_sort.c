#include "sort.h"
#define test 0

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

size_t partition(int *array, size_t low, size_t high)
{
    int pivot = array[high];
    size_t i = low - 1;
    size_t j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    if (test)
        printf("value of index pivot is %ld\n", i  + 1);
    return i + 1;
}

void quick_sort_recursion(int *array, size_t low, size_t high)
{
    if (low < high)
    {
        size_t pivot_index = partition(array, low, high);
        if (test)
            printf("Low = %ld \t High = %ld\n", low, high);
        if (pivot_index > 1)
        {
                quick_sort_recursion(array, low, pivot_index - 1);
                print_array(array, high);
        }
        if (test)
            printf("Low = %ld \t High = %ld\n \t Pivot Index %ld\n", low, high, pivot_index);
        quick_sort_recursion(array, pivot_index + 1, high);
        if (test)
            printf("Low = %ld \t High = %ld\n", low, high);
        print_array(array, high);
    }
}
void quick_sort(int *array, size_t size)
{
    quick_sort_recursion(array, 0, size - 1);
}