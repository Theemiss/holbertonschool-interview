#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <unistd.h>
#include <stdlib.h>
int _putchar(char c);
int *multiplication(int *num1, int *num2, int len1, int len2);
void storage(char *str, int *array);
void print_array(int *num, int len);
char *reverse_string(char *str);
void _error_printrer(void);
int *alloc_size(int *arr, int size);
void fill_array(int *arr, int len);
int _strlen(char *s);
void check_base10(char *argv[]);

/**
 * _error_printrer - print error message
 *
 */
void _error_printrer(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
}
/**
* reverse_string - reverse a string
* @str: string to reverse
* Return: Reversed string
*/
char *reverse_string(char *str)
{
	char *s, *s2;

	if (!str || !*str)
		return (str);
	for (s = str, s2 = str + _strlen(str) - 1; s2 > s; ++s, --s2)
	{
		*s ^= *s2;
		*s2 ^= *s;
		*s ^= *s2;
	}
	return (str);
}
/**
 * print_array - prints a number takes from array of digits.
 *
 * @num: array we want to print.
 * @len: length of the array.
 *
 * Return: Nothing.
 */
void print_array(int *num, int len)
{
	int i;

	i = 0;
	while (num[i] == 0)
		i++;
	if (i >= len)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}
	for (; i < len; i++)
	{
		_putchar(num[i] + '0');
	}
	_putchar('\n');
}
/**
 * storage - stores a string numbers in arrays by digits
 *
 * @str: string we want to store.
 * @array: array we want to store the number in.
 *
 * Return: Nothing.
 */
void storage(char *str, int *array)
{
	int i;

	for (i = 0; i < _strlen(str); i++)
	{
		array[i] = str[i] - '0';
	}
}
/**
 * multiplication - multiplies reversed numbers
 *
 * @num1: array 1 of number reversed.
 * @num2: array 2 of number reversed.
 * @len1: length of num1.
 * @len2: length of num2.
 *
 * Return: rev(num1) * rev(num2).
 */
int *multiplication(int *num1, int *num2, int len1, int len2)
{
	int len, i, j;
	int *r;

	len = len1 + len2;
	r = NULL;
	r = alloc_size(r, len);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2; j >= 0; j--)
		{
			r[i + j + 1] += num1[len1 - 1 - i] * num2[len2 - 1 - j];
		}
	}

	for (i = len - 1; i >= 0; i--)
	{
		if (r[i] >= 10)
		{
			r[i - 1] += r[i] / 10;
			r[i] = r[i] % 10;
		}
	}
	return (r);
}


#endif
