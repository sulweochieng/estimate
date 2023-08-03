#include "main.h"
#include "types.h"
#include "fprtyps.h"
#include "globals.h"

/**
 * allocate_2D_array - a dynamically allocating memory to a 2-D array.
 * @rows: total possible number of all ratios that can be generated.
 * @cols: the three levels of expertise.
 * Return: the location of the 2-D array.
 */
int **allocate_2D_array(unsigned long long int rows, unsigned int cols)
{
	int **arrays2D = NULL;
	int i, k;

	arrays2D = malloc(sizeof(unsigned long long int) * rows);
	if (!arrays2D)
	{
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < rows; i++)
	{
		arrays2D[i] = malloc(sizeof(unsigned int) * cols);
		if (!arrays2D[i])
		{
			for (j = 0; j < i; j++)
				free(array[j]);
			free(arrays2D);
		}
		exit(EXIT_FAILURE);
	}
	return (arrays2D);
}
