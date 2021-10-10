#include "palindrome.h"
/**
*is_palindrome - check plaindrome for int
*@n: unsigned int to check
*Return: 1 or 0
 */

int is_palindrome(unsigned long n)
{
	int rn = 0, r, o = n;

	while (n != 0)
	{
		r = n % 10;
		rn = rn * 10 + r;
		n /= 10;
	}
	if (o == rn)
		return (1);
	else
		return (0);
}
