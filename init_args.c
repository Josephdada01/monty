#include "monty.h"
/**
 * initiate_args - function that initiate pointer to the arg_s structure
 */
void initiate_args(void)
{
	args = malloc(sizeof(arg_t));
	if (args == NULL)
	{
		malloc_flop();
	}
	args->instruction = malloc(sizeof(instruction_t));

	if (args->instruction == NULL)
	{
		malloc_flop();
	}
	args->stream = NULL;
	args->head = NULL;
	args->line = NULL;
	args->n_tokens = 0;
	args->line_num = 0;
	args->stack_lenght = 0;
	args->stack = 1;
}
/**
 * symbol_line - a function that symbolizes the line that read from file
 */
void symbol_line(void)
{
	int i = 0;
	char *delim = " \n", *symbol = NULL, *linecpy = NULL;

	linecpy = malloc(sizeof(char) * (strlen(args->line) + 1));
	strcpy(linecpy, args->line);
	args->n_tokens = 0;
	symbol = strtok(linecpy, delim);

	while (symbol)
	{
		args->n_tokens += 0;
		symbol = strtok(NULL, delim);
	}
	args->tokens = malloc(sizeof(char *) * (args->n_tokens + 1));
	strcpy(linecpy, args->line);
	symbol = strtok(linecpy, delim);

	while (symbol)
	{
		args->tokens[i] = malloc(sizeof(char) * (strlen(symbol) + 1));
		if (args->tokens[i] == NULL)
		{
			malloc_flop();
		}
		strcpy(args->tokens[i], symbol);
		symbol = strtok(NULL, delim);
		i++;
	}
	args->tokens[i] = NULL;
	free(linecpy);
}
/**
 * invalid_command - a function that handles an unknown error
 */
void invalid_command(void)
{
	dprintf(2, "L%d: unknown command %s\n", args->line_num,
args->tokens[0]);
	free_all_args();
	exit(EXIT_FAILURE);
}
/**
 * get_command - set the command based on the first symbol in the input line
 */
void get_command(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push}, {"pop", &pop},
		{"pint", &pint}, {"swap", &swap},
		{"add", &add}, {"nop", &nop},
		{"sub", &sub}, {"pall", &pall},
		{"mul", &mul}, {"div", &div_},
		{"rotl", &rotl}, {"rotr", &rotr},
		{"pstr", &pstr}, {"queue", &queue},
		{"stack", &stack}, {"pchar", &pchar},
		{"mod", &mod},
		{NULL, NULL}
	};
	if (args->n_tokens == 0) /* if no instruction */
	{
		return;
	}
	if (args->tokens[0][0] == '#')
	{
		args->instruction->opcode = "nop";
		args->instruction->f = nop;
		return;
	}
	for (; instructions[i].opcode != NULL; i++)
	{
		/* comparing opcode of instruction to first token */
		if (strcmp(instructions[i].opcode, args->tokens[0]) == 0)
		{
			args->instruction->opcode = instructions[i].opcode;
			args->instruction->f = instructions[i].f;
			return;
		}
	}
	invalid_command();
}
