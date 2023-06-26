#include "shell.h"

/**
 * env_get_key - gets the value of an environment variable.
 * @key: the environment variable of interest
 * @data: struct of the program's data
 * Return: a pointer to the value of the variable
 *	or 0 if it doesn't exist
 */
char *env_get_key(char *key, data_of_program *data)
{
	int x, key_leng = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_leng = str_length(key);

	for (x = 0; data->env[x]; x++)
	{
		if (str_compare(key, data->env[x], key_leng) &&
		 data->env[x][key_leng] == '=')
		{
			return (data->env[x] + key_leng + 1);
		}
	}

	return (NULL);
}

/**
 * env_set_key - overwrite the value of the environment variable
 * or create it if does not exist.
 * @key: name of the variable to set
 * @value: new value
 * @data: struct of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int x, key_leng = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_leng = str_length(key);

	for (x = 0; data->env[x]; x++)
	{
		if (str_compare(key, data->env[x], key_leng) &&
		 data->env[x][key_leng] == '=')
		{
			is_new_key = 0;
			free(data->env[x]);
			break;
		}
	}

	data->env[x] = str_concat(str_duplicate(key), "=");
	data->env[x] = str_concat(data->env[x], value);

	if (is_new_key)
	{
		data->env[x + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - remove a key from the environment
 * @key: the key to remove
 * @data: the sructure of the program's data
 * Return: 1 if the key was removed,
 *	0 if the key does not exist;
 */
int env_remove_key(char *key, data_of_program *data)
{
	int x, key_leng = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_leng = str_length(key);

	for (x = 0; data->env[x]; x++)
	{
		if (str_compare(key, data->env[x], key_leng) &&
		 data->env[x][key_leng] == '=')
		{
			free(data->env[x]);

			x++;
			for (; data->env[x]; x++)
			{
				data->env[x - 1] = data->env[x];
			}
			data->env[x - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - prints the current environ
 * @data: struct for the program's data
 * Return: nothing
 */
void print_environ(data_of_program *data)
{
	int x;

	for (x = 0; data->env[x]; x++)
	{
		_print(data->env[x]);
		_print("\n");
	}
}
