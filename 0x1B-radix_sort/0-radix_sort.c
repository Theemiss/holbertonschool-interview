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
 * radix_sort - Sort an array using radix sort
 *@array: array to sort
 *@size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t bucket[10][10], bucket_cnt[10];
	size_t i, j, k, r, NOP = 0, divisor = 1, lar, pass;

	lar = find_max(array, size);
	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				array[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
		print_array(array, size);
	}
}
