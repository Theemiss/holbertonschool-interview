#include "sort.h"
/**
* merge_sort -  sort an array using merge sort
* @array: array to sort
* @size: size of the array
* return: void
*/
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i = 0;

	if (!array || size < 2)
		return;
	copy = malloc(size * sizeof(int));
	if (!copy)
		return;
	for (; i < size; i++)
	{
		copy[i] = array[i];
	}
	split(array, copy, 0, size);
	free(copy);
}
/**
*split - split an array
*@arr: arr to sort
*@copy: copy of the arr to sort
*@start: starting index of the array
*@end: ending index of the array
*/
void split(int *arr, int *copy, int start, int end)
{
	int middle = start + (end - start) / 2;

	if (end - start <= 1)
		return;
	split(copy, arr, start, middle);
	split(copy, arr, middle, end);
	merge(arr, copy, start, end, middle);

}
/**
* merge - merge two array
* @arr: array to sort
* @copy: copy of the array to sort
* @s: starting index
* @e:  ending index
* @m: middle index
*/
void merge(int *arr, int *copy, int s, int e, int m)
{
	int start, end, i = s;

	start = s;
	end = m;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(copy + s, m - s);
	printf("[right]: ");
	print_array(copy + m, e - m);
	while (start < m && end < e)
	{
		if (copy[start] < copy[end])
		{
			arr[i] = copy[start];
			start++;
		}
		else
		{
			arr[i] = copy[end];
			end++;
		}
	i++;
	}
	while (start < m)
	{
		arr[i] = copy[start];
		i++;
		start++;
	}
	while (end <= e)
	{
		arr[i] = copy[end];
		i++;
		end++;
	}
	printf("[Done]: ");
	print_array(arr + s, e - s);
}
