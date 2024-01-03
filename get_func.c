#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

/**
 * get_func - asdf
 * @s: string/ function
 */
void get_func(char *s)
{
	stack_t funcs[] = {
		{"push", push},
		{"pall", pall},
		};
}
