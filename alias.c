#include "shell.h"

/**
 * print_alias - add, remove or show aliases to printf.
 * @data: struct for the program's data
 * @alias: name of the alias to be printed
 * Return: 0 if sucess, or other number if its declared in the arguments
 */
int print_alias(data_of_program *data, char *alias)
{
	int x, y, alias_leng;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_leng = str_length(alias);
		for (x = 0; data->alias_list[x]; x++)
		{
			if (!alias || (str_compare(data->alias_list[x], alias, alias_leng)
				&&	data->alias_list[x][alias_leng] == '='))
			{
				for (y = 0; data->alias_list[x][y]; y++)
				{
					buffer[j] = data->alias_list[x][y];
					if (data->alias_list[x][y] == '=')
						break;
				}
				buffer[y + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[x] + y + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */
char *get_alias(data_of_program *data, char *name)
{
	int x, alias_leng;

	if (name == 0 || data->alias_list == 0)
		return (0);

	alias_leng = str_length(name);

	for (x = 0; data->alias_list[x]; x++)
	{
		if (str_compare(name, data->alias_list[x], alias_leng) &&
			data->alias_list[x][alias_leng] == '=')
		{
			return (data->alias_list[x] + alias_leng + 1);
		}
	}

	return (0);

}

/**
 * set_alias - add, or override alias
 * @alias_string: alias to be seted in the form (name='value')
 * @data: struct for the program's data
 * Return: 0 if sucess, or other number if its declared in the arguments
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int x, y;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL || data->alias_list == NULL)
		return (1);

	for (x = 0; alias_string[x]; x++)
		if (alias_string[x] != '=')
			buffer[x] = alias_string[x];
		else
		{
			temp = get_alias(data, alias_string + x + 1);
			break;
		}

	for (y = 0; data->alias_list[y]; y++)
		if (str_compare(buffer, data->alias_list[y], x) &&
			data->alias_list[y][x] == '=')
		{
			free(data->alias_list[y]);
			break;
		}

	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[y] = str_duplicate(buffer);
	}
	else
		data->alias_list[y] = str_duplicate(alias_string);
	return (0);
}
