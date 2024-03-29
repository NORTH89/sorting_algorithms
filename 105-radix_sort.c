#include "sort.h"

/**
 * csort2 - sorts an array of integers
 * @array: array to be sorted
 * @buff: buffer
 * @size: size of array
 * @lsd: least significant digit
 * Return: void
 */

void csort2(int *array, int **buff, int size, int lsd)
{
	int a, b, csize = 10, num;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (a = 0; a < size; a++)
	{
		num = array[a];
		for (b = 0; b < lsd; b++)
			if (b > 0)
				num = num / 10;
		num = num % 10;
		buff[num][carr[num]] = array[a];
		carr[num] += 1;
	}

	for (a = 0, b = 0; a < csize; a++)
	{
		while (carr[a] > 0)
		{
			array[b] = buff[a][carr2[a]];
			carr2[a] += 1, carr[a] -= 1;
			b++;
		}
	}

	print_array(array, size);
}

/**
 * csort - sorts an array of integers
 * @array: array to be sorted
 * @size: size of array
 * @lsd: least significant digit
 * Return: void
 */
void csort(int *array, int size, int lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a, b, num, csize = 10, **buff;

	for (a = 0; a < size; a++)
	{
		num = array[a];
		for (b = 0; b < lsd; b++)
			if (b > 0)
				num = num / 10;
		num = num % 10;
		carr[num] += 1;
	}

	if (carr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (a = 0; a < csize; a++)
		if (carr[a] != 0)
			buff[a] = malloc(sizeof(int) * carr[a]);

	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (a = 0; a < csize; a++)
		if (carr[a] > 0)
			free(buff[a]);
	free(buff);
}

/**
 * radix_sort - sorts an array of integers
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
