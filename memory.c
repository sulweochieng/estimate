#include "main.h"

/**
 * array_alloc - a dynamically allocating memory to a 2-D array.
 * @rows: total possible number of all ratios that can be generated.
 * @cols: the three levels of expertise.
 * Return: the location of the 2-D array.
 */
int **array_alloc(unsigned long long int rows, unsigned int cols)
{
	int **arrayRatios = NULL;
	int i, k;

	arrayRatios = malloc(sizeof(int) * rows);
	if (!arraRatios)
	{
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < rows; i++)
	{
		arrayRAtio[i] = malloc(sizeof(int) * rows);
		if (!arrayRatio[i])
		{
			for (j = 0; j < i; j++)
				free(array[j]);
			free(arrayRatio);
		}
		exit(EXIT_FAILURE);
	}
	return (arrayRatio);
}
