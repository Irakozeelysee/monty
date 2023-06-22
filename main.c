#include "monty.h"

/**
 * main - the entry point
 * @argc: the argument count
 * @argv: the argument vector
 * Return: on success it returns 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process(argv[1]);
	return (0);
}
