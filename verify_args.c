#include "monty.h"
/**
 * verify_arguments - a function that check number of commands line in args
 * @argc: the number of command line
 */
void verify_arguments(int argc)
{
	if (argc == 2)
	{
		return;
	}
	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * malloc_flop - a fuction that handles error when malloc failed
 */
void malloc_flop(void)
{
	dprintf(2, "Error: malloc flop woefully\n");
	free_args();
	exit(EXIT_FAILURE);
}
/**
 * get_stream_flop - the function handles error while handling error
 * @filename: the failed file
 */
void get_stream_flop(char *fIlename)
{
	dprintf(2, "Error: can't access the file %s\n", fIlename);
	free_args();
	exit(EXIT_FAILURE);
}
/**
 * get_streaming - get stream from specified file
 * @filename: the specified file
 */
void get_streaming(char *fIlename)
{
	FILE *file = fopen(fIlename, "r");
	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", fIlename);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	args->stream = file;
}
