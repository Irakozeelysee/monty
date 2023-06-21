#include "monty.h"
#define BUFFER 10000

/**
 * main - entry point
 * @argc: argument count
 * @argv: the argument vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int fd, check_push = 0;
	unsigned int line_number = 1;
	ssize_t num_read;
	char *buffer, *token;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * BUFFER);
	if (buffer == NULL)
		return (0);
	num_read = read(fd, buffer, BUFFER);
	if (num_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " \n\t\a\r;:");
	while (token != NULL)
	{
		if (check_push == 1)
		{
			push(&stack, line_number, token);
			check_push = 0;
			token = strtok(NULL, " \n\t\a\r;:");
			line_number++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			check_push = 1;
			token = strtok(NULL, " \n\t\a\r;:");
			continue;
		}
		else if (token[0] == '#')
		{
			token = strtok(NULL, " \n\t\a\r;:");
			continue;
		}
		else
		{
			if (get_func(token) != 0)
			{
				get_func(token)(&stack, line_number);
			}
			else
			{
				free_list(&stack);
				printf("L%d: unknown instructions %s\n", line_number, token);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
		token = strtok(NULL, " \n\t\a\r;:");
	}
	free_list(&stack);
	free(buffer);
	close(fd);
	return (0);
}
