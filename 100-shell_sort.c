#include "sort.h"
/**
 * shell_sort - function
 * @array: pointer to array
 * @size: index of the start
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i = 0;
	int j = 0, ii = 0, tmp;

	if (!array || size < 2)
		return;
	while (gap <= size)
	{
		if (gap * 3 + 1 > size)
			break;
		gap = gap * 3 + 1;
	}
	for (i = 0, gap = gap; gap > 1 && i + gap < size; gap = (gap - 1) / 3, i++)
	{
		if (array[i] > array[i + gap])
		{
			for (j = i + gap, ii = i; j >= 0 && ii >= 0 && array[ii] > array[j];
				 j = j - gap, ii = ii - gap)
			{
				tmp = array[j];
				array[j] = array[ii];
				array[ii] = tmp;
			}
		}
		print_array(array, size);
	}
	for (i = 1; i < size; i++)
	{
		if (array[i - 1] > array[i])
		{
			for (j = i - 1, ii = i; j >= 0 && array[ii] < array[j]; j--, ii--)
			{
				tmp = array[ii];
				array[ii] = array[j];
				array[j] = tmp;
			}
		}
	}

	print_array(array, size);
}
