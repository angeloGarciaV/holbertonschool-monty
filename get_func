#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

/**
 * get_func - function that selects the correct function to perform
 * Return: pointer to the function that corresponds to the opcode
 */
void (*get_func(void))(stack_t **, unsigned int)
{
	int i = 0, j = 0;
	int len = 0;
	int valid_func = 0;
	char *buff = NULL;
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{NULL, NULL}
		};

		while (funcs[i].opcode)
	{
		i = 0;
		valid_func = 1;
		len = strlen(funcs[i].opcode);
		while (j < len)
		{
			if (funcs[i].opcode[j] != buff[j])
			{
				valid_func = 0;
				break;
			}
			j++;
		}
		if (valid_func == 1 && (buff[j] == '\n'
			|| buff[j] == ' ' || buff[j] == '\0'))
			break;
		i++;
	}
	return (funcs[i].f);
}
