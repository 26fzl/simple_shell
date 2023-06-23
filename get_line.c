#include "shell.h"

/**
* _getline - Read a single line from the prompt.
* @data: data struct for the program
*
* Return: reading counting bytes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, x = 0;

	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		for (x = 0; array_commands[x]; x++)
		{
			free(array_commands[x]);
			array_commands[x] = NULL;
		}

		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		x = 0;
		do {
			array_commands[x] = str_duplicate(_strtok(x ? NULL : buff, "\n;"));

			x = check_logic_ops(array_commands, x, array_operators);
		} while (array_commands[x++]);
	}


	data->input_line = array_commands[0];
	for (x = 0; array_commands[x]; x++)
	{
		array_commands[x] = array_commands[x + 1];
		array_operators[x] = array_operators[x + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - verify and split for && and || operators
* @array_commands: array of the commands.
* @x: index in the array_commands to check
* @array_operators: array of the logical operators
*
* Return: index of the last command in the array_commands.
*/
int check_logic_ops(char *array_commands[], int x, char array_operators[])
{
	char *temp = NULL;
	int y;


	for (y = 0; array_commands[x] != NULL  && array_commands[x][y]; y++)
	{
		if (array_commands[x][y] == '&' && array_commands[x][y + 1] == '&')
		{
			temp = array_commands[x];
			array_commands[x][y] = '\0';
			array_commands[x] = str_duplicate(array_commands[x]);
			array_commands[y + 1] = str_duplicate(temp + y + 2);
			x++;
			array_operators[x] = '&';
			free(temp);
			y = 0;
		}
		if (array_commands[x][y] == '|' && array_commands[x][y + 1] == '|')
		{
			temp = array_commands[x];
			array_commands[x][y] = '\0';
			array_commands[x] = str_duplicate(array_commands[x]);
			array_commands[x + 1] = str_duplicate(temp + y + 2);
			x++;
			array_operators[x] = '|';
			free(temp);
			y = 0;
		}
	}
	return (x);
}
