#include "sort.h"

/**
 * swap_items - Swaps two items in an array
 *
 * @array: The array
 * @l: The left index
 * @r: The right index
 *
 * Return: Nothing
 */
void swap_items(int *array, size_t l, size_t r)
{
	int cmp;

	if (array != NULL)
	{
		cmp = array[l];
		array[l] = array[r];
		array[r] = cmp;
	}
}

/**
 * quick_sort_range_lomuto - Sorts an array of integers
 *
 * @array: The array
 * @low: The left index
 * @high: The right index
 * @size: The number of elements in the array
 *
 * Return: Nothing
 */

void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t a, b;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	a = low;
	for (b = low; b < high; b++)
	{
		if (array[b] <= pivot)
		{
			if (a != b)
			{
				swap_items(array, a, b);
				print_array(array, size);
			}
			a++;
		}
	}
	if (a != high)
	{
		swap_items(array, a, high);
		print_array(array, size);
	}
	if (a - low > 1)
		quick_sort_range_lomuto(array, low, a - 1, size);
	if (high - a > 1)
		quick_sort_range_lomuto(array, a + 1, high, size);
}

/**
 * quick_sort - Sorts an array of integers
 *
 * @array: The array
 * @size: The number of elements in the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
