#include "shell.h"

/**
 * str_length - return the length of a string.
 * @string: pointer
 * Return: length of string.
 */
int str_length(char *string)
{
	int len = 0;

	if (string == NULL)
		return (0);

	while (string[len++] != '\0')
	{
	}
	return (--len);
}

/**
 * str_duplicate - duplicate string
 * @string: String to copy
 * Return: pointer to the array
 */
char *str_duplicate(char *string)
{
	char *result;
	int len, x;

	if (string == NULL)
		return (NULL);

	len = str_length(string) + 1;

	result = malloc(sizeof(char) * len);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (x = 0; x < len ; x++)
	{
		result[x] = string[x];
	}

	return (result);
}

/**
 * str_compare - Compare two strings
 * @string1: String one, shorter
 * @string2: String two, longer
 * @number: number of characters to be compared, 0 if infinite
 * Return: 1 if the strings are equals,0 if the strings are different
 */
int str_compare(char *string1, char *string2, int number)
{
	int itert;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_length(string1) != str_length(string2))
			return (0);
		for (itert = 0; string1[itert]; itert++)
		{
			if (string1[itert] != string2[itert])
				return (0);
		}
		return (1);
	}
	else
	{
		for (itert = 0; itert < number ; itert++)
		{
			if (string1[itert] != string2[itert])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat - concatenates two strings.
 * @string1: String to be concatenated
 * @string2: String to be concatenated
 *
 * Return: pointer to the array
 */
char *str_concat(char *string1, char *string2)
{
	char *result;
	int len1 = 0, len2 = 0;

	if (string1 == NULL)
		string1 = "";
	len1 = str_length(string1);

	if (string2 == NULL)
		string2 = "";
	len2 = str_length(string2);

	result = malloc(sizeof(char) * (len1 + len2 + 1));

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (len1 = 0; string1[len1] != '\0'; len1++)
		result[len1] = string1[len1];
	free(string1);

	for (len2 = 0; string2[len2] != '\0'; len2++)
	{
		result[len1] = string2[len2];
		len1++;
	}

	result[len1] = '\0';
	return (result);
}


/**
 * str_reverse - reverses a string.
 *
 * @string: pointer.
 * Return: void.
 */
void str_reverse(char *string)
{

	int x = 0, len = str_length(string) - 1;
	char h;

	while (x < len)
	{
		h = string[x];
		string[x++] = string[len];
		string[len--] = h;
	}
}
