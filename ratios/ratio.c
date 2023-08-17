#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"
/**
 * generate_ratio_list - generates all possible ratios for computing the
 * estimate costs.
 * @n: the number of specific specialists needed for the project.
 * @ratiosList: struct type to hold the various ratio values [a]:[b]:[c].
 * @count:tracker of all possible ratios got from sharing [n] items among three
 * people.
 */
void generate_ratio_list(int n, ratio *ratiosList, unsigned long int *count)
{
	int a, b, c;
	*count = 0;
	for (a = 1; a <= n - 2; a++)
	{
		for (b = 1; b <= n - a - 1; b++)
		{
			c = (n - a) - b;

			ratiosList[*count].a = a;
			ratiosList[*count].b = b;
			ratiosList[*count].c = c;
			(*count)++;
		}
	}
}
