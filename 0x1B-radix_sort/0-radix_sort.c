#include "sort.h"

/**
 * find_max - determine max value in array of int
 * @arr: array of int
 * @len: size of the array
 * Return: max value of an array
 */
int find_max(int *arr, size_t len)
{
	int max = arr[0];
	size_t i;

	for (i = 0; i < len; i++)
	{
		if (max <= arr[i])
			max = arr[i];
	}
	return (max);
}
/**
 * radix_count_sort - counts the number of digits in the maximum value
 * @array: array to be sorted
 * @size: size of the array
 * @dig: Integer by which the array is divided to get the digit
 * Return: Void
 */
void radix_count_sort(int *array, int size, int dig)
{
	int *bucket, *bucket_cnt, i;

	bucket = malloc(sizeof(int) * size);
	bucket_cnt = malloc(sizeof(int) * (find_max(array, size) + 1));
	if (bucket_cnt == NULL || bucket == NULL)
	{
		free(bucket_cnt);
		free(bucket);
	}
	for (i = 0; i <= find_max(array, size); i++)
		bucket_cnt[i] = 0;
	for (i = 0; i < size; i++)
		bucket_cnt[array[i] / dig % 10]++;
	for (i = 1; i <= find_max(array, size); i++)
		bucket_cnt[i] += bucket_cnt[i - 1];
	for (i = size - 1; i >= 0; i--)
		bucket[bucket_cnt[array[i] / dig % 10]-- - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = bucket[i];
	free(bucket_cnt);
	free(bucket);
}
/**
 * radix_sort - Sort an array using radix sort
 *@array: array to sort
 *@size: size of the array
 */
void radix_sort(int *array, size_t size)
{

	int i;
	int max;

	if (array == NULL || size <= 1)
	{
		return;
	}
	max = find_max(array, size);
	for (i = 1; max / i > 0; i *= 10)
	{
		radix_count_sort(array, size, i);
		print_array(array, size);
	}
}
