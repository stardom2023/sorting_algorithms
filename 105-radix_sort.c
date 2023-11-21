#include "sort.h"
#include <stdio.h>
/**
* getMax - A utility function to get maximum value in arr[]
* @arr: array
* @n: size of the array
* Return: array
*/
int getMax(int *arr, int n)
{
	int f, max = arr[0];

	for (f = 1; f < n; f++)
		if (arr[f] > max)
			max = arr[f];
	return (max);
}

/**
* countSort - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @arr: array
* @n: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int f;
	int ount[10] = {0};

	for (f = 0; f < (int)n; f++)
		ount[(arr[f] / exp) % 10]++;

	for (f = 1; f < 10; f++)
		ount[f] += ount[f - 1];

	/* Build the output array */
	for (f = n - 1; f >= 0; f--)
	{
		output[ount[(arr[f] / exp) % 10] - 1] = arr[f];
		ount[(arr[f] / exp) % 10]--;
	}

	for (f = 0; f < (int)n; f++)
		arr[f] = output[f];
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know number of digits */
	int exp, maximum = 0;
	int *output = '\0';

	if (array == 0 || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == 0)
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
