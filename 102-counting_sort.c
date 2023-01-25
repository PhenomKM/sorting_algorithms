#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * max - finds maximum integer in an array.
 *
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: max of the integers of the array.
 */
int max(int *array, size_t size)
{
	int max = array[0];
	unsigned int i;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}
/**
 * counting_sort - algorithm to sort an array of positive integers.
 *
 * @array: array of integers.
 * @size: size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int *count_arr, *new_array, i, maxi;

	if (!array || size < 2)
		return;

	maxi = max(array, size) + 1;

	count_arr = malloc(maxi * sizeof(int));
	if (!count_arr)
		return;
	new_array = malloc(size * sizeof(int));
	if (!new_array)
		return;

	for (i = 0; i < maxi; i++)
	{
		count_arr[i] = 0;
	}
	for (i = 0; (unsigned int) i < size; i++)
	{
		count_arr[array[i] - 1] += 1;
	}
	for (i = 0; i < maxi; i++)
	{
		if (i == 0)
			continue;
		count_arr[i] = count_arr[i] + count_arr[i - 1];
	}
	for (i = 0; (unsigned int) i < size; i++)
	{
		new_array[count_arr[array[i]]] = array[i];
		count_arr[array[i] - 1] -= 1;
	}
	print_array(count_arr, maxi);
	for (i = 0; (unsigned int) i < size ; i++)
		array[i] = new_array[i + 1];
	free(new_array);
	free(count_arr);
}
