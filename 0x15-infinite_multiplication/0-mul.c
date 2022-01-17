#include "holberton.h"
/**
* main - main function
* @argc: argument count
* @argv: arguments
* Return: int
*/
int main(int argc, char *argv[])
{
	char *a = argv[1];
	char *b = argv[2];
	int *num1, *num2, *res;
	int len_a, len_b;

	if (argc != 3)
	{
		_error_printrer();
		exit(98);
	}
	check_base10(argv);
	len_a = _strlen(a);
	len_b = _strlen(b);
	num1 = NULL;
	num2 = NULL;
	res = NULL;

	num1 = alloc_size(num1, len_a);
	num2 = alloc_size(num2, len_b);

	storage(reverse_string(a), num1);
	storage(reverse_string(b), num2);

	res = multiplication(num1, num2, len_a, len_b);
	print_array(res, len_a + len_b);

	free(num1);
	free(num2);
	free(res);
	return (0);
}
/**
* check_base10 - check if string is a number and base10
*@argv: arguments
*
*/
void check_base10(char *argv[])
{
	int i;
	char *num1, *num2;

	num1 = argv[1];
	num2 = argv[2];
	for (i = 0; i < _strlen(num1); i++)
	{
		if (num1[i] > '9' || num1[i] < '0')
		{
			_error_printrer();
			exit(98);
		}
	}
	for (i = 0; i < _strlen(num2); i++)
	{
		if (num2[i] > '9' || num2[i] < '0')
		{
			_error_printrer();
			exit(98);
		}
	}
}
/**
 * _strlen - find len
 * @s: char* to calculate len
 * Return: len of an array
 */
int _strlen(char *s)
{
	int l = 0;

	while (s[l])
	{
		l++;
	}
	return (l);
}
/**
 * fill_array - fill an array by 0
 * @arr: array to fill
 * @len: size of the array
 */
void fill_array(int *arr, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}
/**
 * alloc_size - alloc a array and fill it with zero
 * @arr: array to alloc
 * @size: size of the array to alloc
 * Return: new alloced array with 0
 */
int *alloc_size(int *arr, int size)
{
	arr = malloc(size * sizeof(int));
	if (!arr)
	{
		_error_printrer();
		exit(98);
	}
	fill_array(arr, size);
	return (arr);
}
