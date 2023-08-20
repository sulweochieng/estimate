#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * optimum_a - uses [a]/ Senior Dev number at maximum.
 * @n: the total number of Devs needed for the project.
 * @choice: type ratio that will store the ratio chosen.
 */
void optimum_a(int n, ratio *choice)
{
	int a, b, c;

	choice->a = 0;
	choice->b = 0;
	choice->c = 0;

	for (a = 1; a <= n - 2; a++)
	{
		for (b = 1; b <= n - a - 1; b++)
		{
			c = n - a - b;
			if (c > 0)
			{
				choice->a = c;
				choice->b = b;
				choice->c = a;
				return;
			}
		}
	}
}

/**
 * optimum_b - uses [b]/ Mid-Level Dev number at maximum.
 * @n: the total number of Devs needed for the project.
 * @choice: type ratio that will store the ratio chosen.
 */
void optimum_b(int n, ratio *choice)
{
	int a, b, c;

	choice->a = 0;
	choice->b = 0;
	choice->c = 0;

	for (a = 1; a <= n - 2; a++)
	{
		for (b = 1; b <= n - a - 1; b++)
		{
			c = n - a - b;
			if (c > 0)
			{
				choice->a = a;
				choice->b = c;
				choice->c = b;
				return;
			}
		}
	}
}

/**
 * optimum_c - uses [c]/ Junior Dev number at maximum.
 * @n: the total number of Devs needed for the project.
 * @choice: type ratio that will store the ratio chosen.
 */
void optimum_c(int n, ratio *choice)
{
	int a, b, c;

	choice->a = 0;
	choice->b = 0;
	choice->c = 0;

	for (a = 1; a <= n - 2; a++)
	{
		for (b = 1; b <= n - a - 1; b++)
		{
			c = n - a - b;
			if (c > 0)
			{
				choice->a = a;
				choice->b = b;
				choice->c = c;
				return;
			}
		}
	}
}
