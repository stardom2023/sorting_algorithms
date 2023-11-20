#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int pid;

	pid = *a;
	*a = *b;
	*b = pid;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *ini;
	size_t z, s;

	if (array == NULL || size < 2)
		return;

	for (z = 0; z < size - 1; z++)
	{
		ini = array + z;
		for (s = z + 1; s < size; s++)
			ini = (array[s] < *ini) ? (array + s) : ini;

		if ((array + z) != ini)
		{
			swap_ints(array + z, ini);
			print_array(array, size);
		}
	}
}
