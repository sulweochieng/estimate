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
int **allocate_2D_array(unsigned long int rows, unsigned int cols)
{
	int **arrays2D = NULL;
	unsigned long int i, j;

	arrays2D = malloc(sizeof(unsigned long int) * rows);
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
				free(arrays2D[j]);
			free(arrays2D);
		}
		exit(EXIT_FAILURE);
	}
	return (arrays2D);
}

/**
 * free_2D_array - deallocating memory for members within a 2-D arrays, and
 * eventually deallocating the 2-D array itself.
 * @array2D: the array whose members and itself is to be deallocated.
 * @rowSize: the number of rows of the 2-D array.
 */
void free_2D_array(int **array2D, unsigned long int rowSize)
{
	unsigned long int i;

	for (i = 0; i < rowSize; i++)
		free(array2D[i]);
	free(array2D);
}
