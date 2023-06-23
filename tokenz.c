#include "shell.h"
/**
 * tokenize - separate the string using a designed delimiter
 * @data: a pointer
 *
 * Return: an array of the different parts of the string
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t";
	int x, y, count = 2, len;

	len = str_length(data->input_line);
	if (len)
	{
		if (data->input_line[len - 1] == '\n')
			data->input_line[len - 1] = '\0';
	}

	for (x = 0; data->input_line[x]; x++)
	{
		for (y = 0; delimiter[y]; y++)
		{
			if (data->input_line[x] == delimiter[y])
				count++;
		}
	}

	data->tokens = malloc(count * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	x = 0;
	data->tokens[x] = str_duplicate(_strtok(data->input_line, delimiter));
	data->command_name = str_duplicate(data->tokens[0]);
	while (data->tokens[x++])
	{
		data->tokens[x] = str_duplicate(_strtok(NULL, delimiter));
	}
}
