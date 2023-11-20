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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t z, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (z = 0; z < len - 1; z++)
		{
			if (array[z] > array[z + 1])
			{
				swap_ints(array + z, array + z + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
