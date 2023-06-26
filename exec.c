#include "shell.h"
/**
 * execute - execute a command with its entire path variables.
 * @data: a pointer to the program's data
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(data_of_program *data)
{
	int rtvl = 0, stus;
	pid_t pidd;

	rtvl = builtins_list(data);

	if (rtvl != -1)
		return (rtvl);

	rtvl = find_program(data);
	if (rtvl)
	{
		return (rtvl);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			rtvl = execve(data->tokens[0], data->tokens, data->env);
			if (rtvl == -1)
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&stus);
			if (WIFEXITED(stus))
				errno = WEXITSTATUS(stus);
			else if (WIFSIGNALED(stus))
				errno = 128 + WTERMSIG(stus);
		}
	}
	return (0);
}
