#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * optimumA - uses [a]/ Senior Dev number at maximum.
 * @n: the total number of Devs needed for the project.
 * @choice: type ratio that will store the ratio chosen.
 */
void optimumA(int A, ratio *choice)
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
 * optimumB - uses [b]/ Mid-Level Dev number at maximum.
 * @n: the total number of Devs needed for the project.
 * @choice: type ratio that will store the ratio chosen.
 */
void optimumB(int A, ratio *choice)
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
 * optimumC - uses [c]/ Junior Dev number at maximum.
 * @n: the total number of Devs needed for the project.
 * @choice: type ratio that will store the ratio chosen.
 */
void optimumC(int A, ratio *choice)
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
