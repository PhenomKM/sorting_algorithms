#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
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
* shell_sort - sorts an array of integers in ascending order using
* the Shell sort algorithm
* @array: array
* @size: size of array
*/
void shell_sort(int *array, size_t size)
{
unsigned int gap = 1;
unsigned int i;
unsigned int j;
int temp = 0;
if (!array || size < 2)
return;
while (gap * 3 + 1 < size)
gap = gap * 3 + 1;
while (gap > 0)
{
for (i = gap; i < size; i++)
{
for (j = i; j > gap - 1; j -= gap)
{
if (array[j - gap] >= array[j])
{
temp = array[j];
array[j] = array[j - gap];
array[j - gap] = temp;
}
}
}
gap = (gap - 1) / 3;
print_array(array, size);
}
}
