#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
* swap - function that swaps elements in array
* @array: array to modify
* @i: int
* @j: int
* Return: nothing
*/
void swap(int *array, int i, int j)
{
int tmp;
tmp = array[i];
array[i] = array[j];
array[j] = tmp;
}
/**
* partition - lomuto partition scheme
* @array: array to deal with
* @high: highest index
* @low: the first index of the array
* @size: size of the array
* Return: integer
*/
int partition(int *array, int low, int high, size_t size)
{
int pivot, i = low, j = 0;
(void) size;
pivot = array[high];
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
if (i != j)
{
swap(array, i, j);
print_array(array, size);
}
i++;
}
}
if (array[i] != array[high])
{
swap(array, i, high);
print_array(array, size);
}
return (i);
}
/**
 * q_sort - recursive function that  does the quick sort method.
 * @array: the array
 * @low: the first index of giving array.
 * @high: highest index of giving array.
 * @size: size of the total array.
**/
void q_sort(int *array, int low, int high, size_t size)
{
int pivot;
if (low < high)
{
pivot = partition(array, low, high, size);
q_sort(array, low, pivot - 1, size);
q_sort(array, pivot + 1, high, size);
}
}
/**
* quick_sort - function that sorts an array of integers in ascending order
* @array: array to sort
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
q_sort(array, 0, size - 1, size);
}
