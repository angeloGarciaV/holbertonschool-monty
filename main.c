#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *bytecode_file = fopen(argv[1], "r");

    if (!bytecode_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, bytecode_file) != -1)
    {
        line_number++;
	}

    free(line);
    fclose(bytecode_file);

    return EXIT_SUCCESS;
}

