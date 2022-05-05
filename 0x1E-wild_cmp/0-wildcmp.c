#include "holberton.h"
/**
 * wildcmp - compare too S1 with taking in consideration wildcard *
 * @s1: pointer to char
 * @s2: pointer to char
 * Return: 1 if string are identical 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0' && *s1 == '\0')
		return (1);

	if (*s2 == *s1)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	return (0);
}
