#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * clear_input_buffer - clears input buffer.
 * Description: called just before calling a function that takes in a user's
 * input from the keyboard, to avoid accidentallly capturing an empty string as
 * input before a user actually inputs.
 */
void clear_input_buffer(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		;
}

/**
 * user_input_string - a function that reads a string from a user and returns a
 * pointer to the read stream and stores it unto a buffer.
 * Description: this function is designed to read a string from the stdin. The
 *	input might include several spaces. But when the function encounters a
 *	newline charactor or end of file, it returns, indicating the end of
 *	input form the user.
 * Return: returns a pointer to the beginning of the of the read stream.
 */
char *user_input_string(void)
{
	int c, i = 0, initialBufferSize = BUFSIZE;
	char *buffer = NULL;

	buffer = malloc(sizeof(char) * initialBufferSize);
	if (!buffer)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}

	while ((c = getchar()) != EOF && c != '\n')
	{
		buffer[i] = c;
		++i;
		if (i >= initialBufferSize - 1)
		{
			initialBufferSize += BUFSIZE;
			buffer = realloc(buffer, sizeof(char) * initialBufferSize);
			if (!buffer)
			{
				printf("Failed to allocate memory!\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	buffer[i] = '\0';
	return (buffer);
}

/**
 * string_input_check - checks if the use has inputed a valid string.
 * @buffer: the string input to validate.
 * Return: on success returns 0, on failure, returns 1.
 */
int string_input_check(char *buffer)
{
	int i, len;

	len = strlen(buffer);

}

/**
 * to_upper - captilizes a string passed to it.
 * @buffer: the string to capitalise.
 * Return: returns the new capitalised string.
 */
char *to_upper(char *buffer)
{
	int i;
	char *temp = NULL;

	for (i = 0; buffer[i] != NULL; i++)
		temp[i] = toupper(buffer[i]);
	temp[i] = '\0';
	return (temp);
}
