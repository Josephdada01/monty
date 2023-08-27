#include "monty.h"

arg_t *args = NULL;
/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: a pointer that point to an array of strings
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	size_t n = 0;

	verify_arguments(argc);
	initiate_args();
	get_streaming(argv[1]);

	while (getline(&args->line, &n, args->stream) != -1)
	{
		args->line_num += 1;/* this the line number of file */
		symbol_line();/* break the line into words */
		get_command();/* this will get the opcode from tokens array */
		run_command();/* run the function belonging to the opcode */
		free_symbol();/* this will free up memory for the tokens */
	}
	enclose_stream(); /* to close the stream */
	free_args(); /* free up memory for the tokens */

	return (0);
}
