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
	int fd;

	fd = open(fIlename, 0_RDONLY);
	if (fd == -1)
	{
		get_stream_flop(fIlename);
	}
	args->stream = fdopen(fd, "r");
	if (args->stream == NULL)
	{
		close(fd);
		get_stream_flop(fIlename);
	}
}
