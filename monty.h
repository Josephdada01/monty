#ifndef MONTY_H
#define MONTY_H
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
/**
 * struct arg_s - a struct that holds variables
 * @stream: file that connects file to the stream
 * @line: string which will read text from stream
 * @line_num: this track current line numb
 * @tokens: this save tokens from line
 * @instruction: a valid instruction from a line
 * @n_tokens: the numbers of token
 * @head: the top of a stack
 * @stack: used to determine whether to use the queue or stack data structure
 * @stack_lenght: this track the number of nodes in the stack
 */
typedef struct arg_s
{
	FILE *stream;
	char *line;
	unsigned int line_num;
	char **tokens;
	int n_tokens;
	instruction_t *instruction;
	stack_t *head;
	int stack_lenght;
	int stack;
} arg_t;

int main(int argc, char **argv);
void initiate_args(void);
void symbol_line(void);
void get_command(void);
void invalid_command(void);
void free_symbol(void);
void verify_arguments(int argc);
void malloc_flop(void);
int comment_(void);
void get_stream_flop(char *fIlename);
void get_streaming(char *fIlename);
void enclose_stream(void);
void run_command(void);
int is_number(char *str);
void free_args(void);
void free_head(void);
void free_stack(stack_t *head);
void free_all_args(void);
void delet_stack(void);

int dprintf(int fd, const char *format, ...);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
FILE *fdopen(int fd, const char *mode);

extern arg_t *args;

void push(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void div_(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);
void stack(stack_t **stack, unsigned int line_num);
void queue(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
#endif
