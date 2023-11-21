#include "sort.h"
/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, sxt, pid = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
		for (sxt = 0; sxt < size; sxt++)
		{
			if (array[sxt] > array[sxt + 1] && array[sxt + 1])
			{
			pid = array[sxt];
			array[sxt] = array[sxt + 1];
			array[sxt + 1] = pid;
			print_array(array, size);
			}
		}
}
