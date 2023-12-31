#include "shell.h"

/**
 * builtins_list - search for match and execute the associate builtins.
 * @data: struct for the program's data
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 **/
int builtins_list(data_of_program *data)
{
	int itrtr;

	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};
	for (itrtr = 0; options[itrtr].builtin != NULL; itrtr++)
	{
		if (str_compare(options[itrtr].builtin, data->command_name, 0))
			return (options[itrtr].function(data));
	}
	return (-1);
}
