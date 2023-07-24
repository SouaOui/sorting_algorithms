#include "sort.h"
#define test 0
#define comp 0

/**
 * swap - Entry point
 * @a: arg
 * @b: arg
 * Return: -
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Entry point
 * @array: arg
 * @low: arg
 * @high: arg
 * Return: -
 */
size_t partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j;

	comp++;
	if (test)
		printf("%d ", comp);
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);

				if (test)
				{
					printf("-");
				}

				print_array(array, 10);
			}
		}
	}
	swap(&array[i + 1], &array[high]);

	if (test)
	{
		printf("%d ", comp);
		printf("_");
	}
	if (array[i + 1] != array[high])
		print_array(array, 10);
	if (test)
		printf("value of index pivot is %ld\n", i + 1);
	return (i + 1);
}

/**
 * quick_sort_recursion - Entry point
 * @array: arg
 * @low: arg
 * @high: arg
 * Return: -
 */
void quick_sort_recursion(int *array, size_t low, size_t high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		if (test)
			printf("Low = %ld \t High = %ld\n", low, high);
		if (pivot_index > 1)
		{
			quick_sort_recursion(array, low, pivot_index - 1);
		}
		if (test)
			printf("Low = %ld \t High = %ld\n \t Pivot Index %ld\n",
				   low, high, pivot_index);
		if (high > 1)
			quick_sort_recursion(array, pivot_index + 1, high);

		if (test)
			printf("Low = %ld \t High = %ld\n", low, high);
	}
}

/**
 * quick_sort - Entry point
 * @array: arg
 * @size: arg
 * Return: -
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1);
}
