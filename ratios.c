#include "main.h"

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
unsigned long long int binomial_coefficient(int n, int k)
{
	unsigned long long int result = 1;
	int i;

	if (k > (n -k))
		k = (n -k); /*using symmetry to reduce number of iterations*/
	for (i = 0; i < k; i++)
	{
		result *= (n - i);
		result /= (i + 1);
	}
	return (result);
}/*always remember while calling: bionomialCoefficient(n+(k-1), k-1)*/

/******************************************************************************/
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
 * Description: being that we have only 3 salary levels currently,I will use the
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
	
	ratio = malloc(levels * sizeof(int));
	if (!ratio)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	
	ratioVals[0] = a / gcd_val_ab;
	ratioVals[1] = b / gcd_val_ab;
	ratioVals[2] = c / gcd_val_bc;
	for (i = 0; i < SALARYLEVELS; i++)
		ratio[i] = ratioVals[i];

	return (ratio);
}

/**
 * ratios - generates all possible ratios for computing the estimate.
 * @name: the identifcation of the profession in which we are finding the
 * estimate.
 * Description: if the number if the number of ratios are more than 10, ratios()
 * finds the best case scenarios for computing 10 possible ratios.
 * Return: returns an array of arrays of the optimum ratios.
 */
/*int **ratios(profession *name)
{
	int n, a, b, c;
	int **ratiosList = NULL;
	printf("How many %s do you for this project: ", name->name);
	scanf("%d", &n);
	*All possible combinations of items for a (from 1 to n)*/
/*	for (a = 1; a <= n; a++)
	{
		*For second person (from 1 to remaining n)*/
/*		for (b = 1; b <= n - a; b++)
		{
			*Remaining n for the c*/
/*			c = (n - a) - b;

			return (generate_ratio(a, b, c))*/


/*****************************************************************************/

/**
 * For this project's purpose, I'll do the following; for any number of any
 * possible n number of ratios generated when sharing m number of items among
 * the the groups, we will decompose them to only 3 optimum ratios. Herein
 * OPTIMUM is the instace where each member of the ratio body is at maximum. i.e
 * I will choose one array of ratio where member 'a' is at it's highest, 'b' as
 * its highest and subsequently for 'c' at its highest and all these three will
 * be stored in a 2-D array for easy access.
 * I will achieve this by keeping track of the indices where each element (a, b,
 * c) has the highest share. Then selcting the top ratios based on these
 * indices.
 */

/*****************************************************************************/

/**
 * share_of_a - calculates the share of 'a' in the ratio
 * @a: member representative of the Senior level.
 * @b: member representative of the Mid-level.
 * @c: member representative of the Junior level.
 * Return: returns the share of 'a'.
 */
float share_of_a(int a, int b, int c)
{
	return ((float)a / (a + b + c));
}

/**
 * share_of_b - calculates the share of 'a' in the ratio
 * @a: member representative of the Senior level.
 * @b: member representative of the Mid-level.
 * @c: member representative of the Junior level.
 * Return: returns the share of 'a'.
 */
float share_of_b(int a, int b, int c)
{
	return ((float)b / (a + b + c));
} 

/**
 * share_of_a - calculates the share of 'a' in the ratio
 * @a: member representative of the Senior level.
 * @b: member representative of the Mid-level.
 * @c: member representative of the Junior level.
 * Return: returns the share of 'a'.
 */
float share_of_c(int a, int b, int c)
{
	return ((float)c / (a + b + c));
}

/**
 * optimum_ratios - generates optimum ratios from  a list of all possible
 * ratios.
 * Return: a pointer to the array of the various ratios.
 */
int **optimum_ratios(void)
{
	int ***optimum_ratios = NULL;
	int total_combinations = n * (n - 1) / 2;
	int n; /*Number of generated ratios*/
	int **ratios = NULL; /*To store all the generated ratios*/
	int i, j, k;
	float a_share, b_share, c_share;
	int a_max_index = -1, b_max_index = -1, c_max_index = -1;
	float a_max_share = 0.0, b_max_share = 0.0, c_max_share = 0.0;

	ratios = allocate_2D_array(total_combinations, SALARYLEVELS);
	if (ratios != NULL)
	{
	/*********************************************************************/
		/*call the function generating ratios here to store in ratios*/
	/*********************************************************************/

		/*Finding top 3 ratios where a, b, c have the highest shares*/
		for (i = 0; i < n; i++)
		{
			a_share = share_of_a(ratios[i][0], ratios[i][1], ratios[i][2]);
			b_share = share_of_b(ratios[i][0], ratios[i][1], ratios[i][2]);
			c_share = share_of_c(ratios[i][0], ratios[i][1], ratios[i][2]);

			if (a_share > a_max_share)
			{
				a_max_share = a_share;
				a_max_index = i;
			}

			if (b_share > b_max_share)
			{
				b_max_share = b_share;
				b_max_index = i;
			}

			if (c_share > c_max_share)
			{
				c_max_share = c_share;
				c_max_index = i;
			}
		}
		optimum_ratios = allocate_2D_array(3,SALARYLEVELS);
		if (optimum_ratios != NULL)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					optimum_ratios[j][k] = ratios[(j == 0) ?
						a_max_index : (j == 1) ?
						b_max_index : c_max_index][k];
				}
			}
		}
		/*Freeing memory allocated to the original ratios*/
		free_2D_array(ratios, totalCombinations);

		return (optimum_ratios);
	}
	exit(EXIT_FAILURE);
}
