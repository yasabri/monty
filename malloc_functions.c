#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @s1: the str compared type
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals.
 *         or value if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] == s2[x] && s1[x]; x++)
		;
	if (s1[x] > s2[x])
		return (1);
	if (s1[x] < s2[x])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 mean that success 0 if not
 */
int _sch(char *s, char c)
{
	int x = 0;

	while (s[x] != '\0')
	{
		if (s[x] == c)
		{
			break;
		}
		x++;
	}
	if (s[x] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @s: the string cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int x = 0, y = 0;

	if (!s)
		s = ultimo;
	while (s[x] != '\0')
	{
		if (_sch(d, s[x]) == 0 && s[x + 1] == '\0')
		{
			ultimo = s + x + 1;
			*ultimo = '\0';
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 0)
			x++;
		else if (_sch(d, s[x]) == 0 && _sch(d, s[x + 1]) == 1)
		{
			ultimo = s + x + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + y;
			return (s);
		}
		else if (_sch(d, s[x]) == 1)
		{
			y++;
			x++;
		}
	}
	return (NULL);
}
