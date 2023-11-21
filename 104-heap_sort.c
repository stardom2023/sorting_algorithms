#include "sort.h"
#include <stdio.h>

/**
 * swap - utility function to swap to integers
 * @a: integer a
 * @b: integer b
 **/
void swap(int *a, int *b)
{
	int c = *a;

	*a = *b;
	*b = c;
}

/**
 * maxHeapify - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: array
 * @size: size of the array for print
 * @idx: index
 * @n: size of the array to run
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	/* See if left child of root exists and is greater than root*/
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root, if needed*/
	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int f;

	if (array == 0 || size < 2)
		return;

	for (f = (size - 2) / 2; f >= 0; --f)
		maxHeapify(array, size, f, size);

	/**
	* Repeat following steps while heap size is greater than 1.
	*/
	for (f = (size - 1); f > 0; --f)
	{
		swap(&array[0], &array[f]);
		print_array(array, size);

		/* Finally, heapify the root of tree.*/
		maxHeapify(array, size, 0, f);
	}
}
