#include "main.h"
/**
 * is_builtin - Check if a command is a built-in command
 * @array_of_tokens: Array of tokens representing the command
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */
int is_builtin(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
			builtin_index++)
		if (strcmp(array_of_tokens[0],
					builtins[builtin_index].name) == 0)
			return (1);
	return (0);
}

/**
 * builtin_handler - Handle the execution of a built-in command
 * @array_of_tokens: Array of tokens representing the command
 *
 * Return: The return value of the built-in command function,
 * or 0 if the command is not a built-in
 */
int builin_handler(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
			builtin_index++)
	{
		if (strcmp(array_of_tokens[0],
					builtins[builtin_index].name) == 0)
			return (builtins[builtin_index].function(array_of_tokens));
	}
	return (0);
}
