#include "main.h"
/**
 * user_inputS - a function that reads a string from a user and returns a
 * pointer to the read stream and stores it unto a buffer.
 * Description: this function is designed to read a string from the stdin. The
 *	input might include several spaces. But when the function encounters a
 *	newline charactor or end of file, it returns, indicating the end of
 *	input form the user.
 * Return: returns a pointer to the beginning of the of the read stream.
 */
char *user_inputS(void)
{
	int c;
	size_t i = 0, initial_buffer_size = BUFSIZE;
	char *buffer = NULL;

	buffer = malloc(sizeof(char) * initial_buffer_size);
	alloc_err(buffer);
	while ((c = getchar()) != EOF && c != '\n')
	{
		buffer[i] = c;
		i++;
		/* reallocate memory if by any chance it surpurses */
		if (i >= initial_buffer_size - 1)
		{
			initial_buffer_size += BUFSIZE;
			buffer = realloc(buffer, sizeof(char) * initial_buffer_size);
			alloc_err(buffer); /* mem allocation failure check */
		}
	}
	/* DON'T ALLOW user to enter EMPTY STRING */
	if (i == 0 || c == '\n')
	{
		free(buffer);
		return (user_inputS());
	}
	buffer[i] = '\0'; /* Null terminate the input to mark it as a string */
	printf("\n");
	return (buffer);
}
