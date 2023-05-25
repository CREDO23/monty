#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}


/**
 * isnumber - checks if a string is a number
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int isnumber(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}


/**
 * file_error - prints file error message and exits
 * @argv: argv given by main()
 *
 * Desc: print msg if  not possible to open the file
 * Return: nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - prints usage message and exits
 *
 * Desc: if user does not give any file or more than
 * one argument to your program
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

