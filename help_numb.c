#include "shell.h"

/**
 * long_to_string - convert a number to a string.
 * @number: number to convert.
 * @string: buffer that save the number as string.
 * @base: base
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	int indx = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[indx++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[indx++] = letters[-(cociente % base)];
		else
			string[indx++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[indx++] = '-';

	string[indx] = '\0';
	str_reverse(string);
}


/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer to str origen.
 * Return: int of string or 0.
 */
int _atoi(char *s)
{
	int sg = 1;
	unsigned int num = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sg *= -1;
		if (*s == '+')
			sg *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num * sg);
}

/**
 * count_characters - count the coincidences of character in string.
 *
 * @string: pointer.
 * @character: string
 * Return: int of string or 0.
 */
int count_characters(char *string, char *character)
{
	int x = 0, count = 0;

	for (; string[x]; x++)
	{
		if (string[x] == character[0])
			count++;
	}
	return (count);
}
