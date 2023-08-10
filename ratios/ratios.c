/*#include "main.h"
#include "types.h"
#include "fprtyps.h"
#include "globals.h"
*/
#include <stdio.h>
#include <stdlib.h>
#define SALARYLEVELS 3
/**
 * binomial_coefficient - a function that determines the number of possible
 * ratios when dividing 'n' items among 'k' individuals.
 * @n: total number of expertise needed to complete a project.
 * @k: the ratio division, i.e a:b:c => 3, equivalent to the number of salary
 * levels available within every job group.
 * Description: since each ratio is a non-negative int number, I chose to
 *	implement the problem as a "Stars and Bars" problem.
 *	The "Star and Bars" formula for the number of ways to distribute 'n'
 *	identical items into 'k' distinct boxes is: => (n+(k-1)/k-1)) where (n
 *	k) represents the binomial coefficient, also known as "n choose k".
 * Return: returns the total number of possible ratios.
 */
unsigned long int binomial_coefficient(int n, int k)
{
	unsigned long int result = 1;
	int i;

	if (k > (n - k))
		k = (n - k);/*using symmetry to reduce number of iterations*/
	for (i = 0; i < k; i++)
	{
		result *= (n - i);
		result /= (i + 1);
	}
	return (result);
} /*always remember while calling: bionomialCoefficient(n+(k-1), k-1)*/

/*****************************************************************************/
/* To determine the possible ratios to distribute 'n' among 3-levels*/
/*****************************************************************************/
/**
 * gcd - implements the Euclidean algorithm in finding GCD of two numbers.
 * @a: one of the (combination of) number(s).
 * @b: one of the (combination of) number(s).
 * Return: returns the GCD of a and b.
 */
int gcd(int a, int b)
{
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

/**
 * generate_ratio - generate possible ratios of sharing 'n' number of items.
 * Description: we have only 3 salary levels currently,I will use the
 * three variables; a,b and c to represent each salary level.
 * @a: first member, to represent Senior level.
 * @b: second member, to represent Mid-level.
 * @c: second member, to represent junior level.
 * Return: returns the ratios in an array form.
 */
int *generate_ratio(int a, int b, int c)
{
	int gcd_val_ab, gcd_val_bc;
	int *ratio = NULL;
	int ratioVals[SALARYLEVELS];
	int i;

	gcd_val_ab = gcd(a, b);
	gcd_val_bc = gcd(b, c);
	ratio = malloc(SALARYLEVELS * sizeof(int));
	if (!ratio)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	ratioVals[0] = a / gcd_val_ab;
	ratioVals[1] = b / gcd_val_ab;
	ratioVals[2] = c / gcd_val_bc;
	for (i = 0; i < SALARYLEVELS; i++)
		*(ratio + i) = ratioVals[i];

	return (ratio);
}

/**
 * generate_ratio_list - generates all possible ratios for computing the
 * estimate costs.
 * @n: the number of specific specialists needed for the project.
 * Return: returns an array of arrays of the optimum ratios.
 */
int *generate_ratio_list(int n)
{
	int a, b, c;
	unsigned long int numRatios = 0;
	static int *(ratiosList)[SALARYLEVELS];
	unsigned long int listSize;

	/*listSize = binomial_coefficient(n, SALARYLEVELS);*/
	/*ratiosList = malloc(sizeof(int *) * listSize);*/
	/*All possible combinations of items for a (from 1 to n)*/
	for (a = 1; a <= n; a++)
	{
		/*For second person (from 1 to remaining n)*/
		for (b = 1; b <= n - a; b++)
		{
			/*Remaining n for the c*/
			c = (n - a) - b;

			/*ratiosList[numRatios] = malloc(sizeof(int) *
					SALARYLEVELS);
					*/
			/*ratiosList[numRatios] = generate_ratio(a, b, c);*/
			ratiosList[numRatios][0] = a;
			ratiosList[numRatios][1] = b;
			ratiosList[numRatios][2] = c;

			numRatios++;
		}
	}
	printf("possible ratios are %lu: \n", numRatios);
	printf("the list-size is %lu: \n", listSize);
	return (ratiosList);
}

/**
 * optimum_ratios - generates optimum ratios from  a list of all possible
 * ratios.
 * @name: the specific list member we would want to compute ratio for.
 * Return: a pointer to the array of the various ratios.
 */
/*
int **optimum_ratios(node *_name)
{
	int **optimumRatios = NULL, **ratios = NULL, totalCombinations;
	int aMaxIndex = -1, bMaxIndex = -1, cMaxIndex = -1;
	int n, j, k;

	printf("How many %s, do you want in this project: ", _name->data->name);
	scanf("%d", &n);
	totalCombinations = binomial_coefficient(n + (SALARYLEVELS - 1),
			SALARYLEVELS - 1);
	ratios = allocate_2D_array(totalCombinations, SALARYLEVELS);
	if (ratios != NULL)
	{
		ratios = generate_ratio_list(n);
		/*Finding top 3 ratios where a, b, c have the highest shares*/
/*		find_max_shares(ratios, totalCombinations, &aMaxIndex,
				&bMaxIndex, &cMaxIndex);

		optimumRatios = allocate_2D_array(OPTIMUM, SALARYLEVELS);
		if (optimumRatios != NULL)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					optimumRatios[j][k] = ratios[(j == 0) ?
						aMaxIndex : (j == 1) ?
						bMaxIndex : cMaxIndex][k];
				}
			}
		}
		free_2D_array(ratios, totalCombinations);
		ratios = NULL;
		return (optimumRatios);
	}
	exit(EXIT_FAILURE);
}*/
