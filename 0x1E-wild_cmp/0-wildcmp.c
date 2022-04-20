#include "holberton.h"
/**
 * wildcmp - compare too string with taking in consideration wildcard *
 * @s1: pointer to char
 * @s2: pointer to char
 * Return: 1 if strings are identical 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	char *cp = NULL, *mp = NULL;

	while ((*s1) && (*s2 != '*'))
	{
		if (*s2 != *s1)
		{
			return (0);
		}
		s2++;
		s1++;
	}

	while (*s1)
	{
		if (*s2 == '*')
		{
			if (!*++s2)
			{
				return (1);
			}
			mp = s2;
			cp = s1 + 1;
		}
		else if (*s2 == *s1)
		{
			s2++;
			s1++;
		}
		else
		{
			s2 = mp;
			s1 = cp++;
		}
	}

	while (*s2 == '*')
	{
		s2++;
	}
	return (!*s2);
}
