#include "main.h"
/**
 * is_valid_path - Check if a filename represents a valid path
 * @filename: Pointer to the filename string
 *
 * Return: 1 if the filename represents a valid path,
 * 0 otherwise
 */
int is_valid_path(char *filename)
{
	size_t length = strlen(filename);

	if (length >= strlen("../"))
		if (strncmp(filename, "../", strlen("../")) == 0)
			return (1);
	if (length >= strlen("./"))
		if (strncmp(filename, "./", strlen("./")) == 0)
			return (1);
	if (length >= strlen("/"))
		if (strncmp(filename, "/", strlen("/")) == 0)
			return (1);
	return (0);
}

/**
 * filepath_creator - Create a file path by concatenating a
 * directory path with a filename
 * @file_path: Pointer to a pointer to store the created file path
 * @array_of_tokens: Array of tokens representing the directory path
 * @filename: Pointer to the filename string
 * @token_index: Index of the token in the array_of_tokens
 * to use for the directory path
 *
 * The file_path parameter should be a pointer to a pointer
 * that will be allocated and assigned with the created file path.
 * The caller is responsible for freeing
 * the allocated memory when it's no longer needed.
 */
void filepath_creator(char **file_path, char **array_of_tokens,
		char *filename, int token_index)
{
	malloc_char(file_path,
			(strlen(array_of_tokens[token_index]) + strlen(filename) + 2),
			"_which Error: malloc failed for file_path");
	strcpy(*file_path, array_of_tokens[token_index]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * _which - Search for the location of an executable
 * file in the directories specified by PATH
 * @filename: Pointer to the filename string
 *
 * Return: Pointer to the file path if found, NULL otherwise
 */
char *_which(char *filename)
{
	struct stat sb;
	char *path_var, *delimiter, *file_path;
	char **array_of_tokens;
	int token_index, file_path_exist;

	delimiter = ":";
	path_var = _getenv("PATH");
	if (path_var != NULL)
	{
		array_of_tokens = array_maker(path_var, delimiter);
		if (array_of_tokens != NULL)
		{
			for (token_index = 0; array_of_tokens[token_index]; token_index++)
			{
				filepath_creator(&file_path, array_of_tokens, filename, token_index);
				file_path_exist = stat(file_path, &sb);
				if (file_path_exist == 0)
				{
					free_which(&path_var, array_of_tokens);
					return (file_path);
				}
				free(file_path);
			}
			free_which(&path_var, array_of_tokens);
		}
		else
			free(path_var);
	}
	file_path_exist = stat(filename, &sb);
	if (file_path_exist == 0 && is_valid_path(filename))
		return (strdup(filename));
	return (NULL);
}
