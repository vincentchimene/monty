#include "monty.h"

/**
 * main - Start point of the Monty code interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    /* Check command-line arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty byte code file */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Initialize stack and other variables */
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    /* Read and process each line of the file */
    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \t\n");

        if (opcode != NULL)
        {
            if (strcmp(opcode, "push") == 0)
            {
                push(&stack, line_number);
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            else if (strcmp(opcode, "pint") == 0)
            {
                pint(&stack, line_number);
            }
            /* Add more opcode cases as needed */
        }
    }

    /* Clean up resources */
    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}
