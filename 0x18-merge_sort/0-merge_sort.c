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

	copy = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	split(array, 0, size, copy);
	free(copy);
}
/**
 *split - split an array
 *@array: arr to sort
 *@copy: copy of the arr to sort
 *@start: starting index of the array
 *@end: ending index of the array
 */
void split(int *array, int start, int end, int *copy)
{
	int mid = (start + end) / 2;
	int i = 0;

	if (end - start <= 1)
		return;

	split(copy, start, mid, array);
	split(copy, mid, end, array);
	printf("Merging...\n");

	printf("[left]: ");
	for (i = start; i < mid; i++)
	{
		printf("%d", copy[i]);
		if (i < mid - 1)
			printf(", ");
	}

	printf("\n[right]: ");
	for (i = mid; i < end; i++)
	{
		printf("%d", copy[i]);
		if (i < end - 1)
			printf(", ");
	}

	merge(array, start, mid, end, copy);

	printf("\n");
	printf("[Done]: ");
	for (i = start; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n");
}
/**
 * merge - merge two array
 * @array: array to sort
 * @copy: copy of the array to sort
 * @start: starting index
 * @end:  ending index
 * @mid: middle index
 */
void merge(int *array, int start, int mid, int end, int *copy)
{
	int s = start;
	int m = mid;
	int i = 0;

	for (i = start; i < end; i++)
	{

		if (s < mid && (m >= end || copy[s] <= copy[m]))
		{
			array[i] = copy[s];
			s = s + 1;
		}
		else
		{
			array[i] = copy[m];
			m = m + 1;
		}
	}
}
