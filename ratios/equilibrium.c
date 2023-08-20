#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * equilibrium_a -determins equillibrium whence [a]/Senior Dev has the highest
 * number.
 * @n: the number of Devs needed for the project.
 * @equilibrium: varibale to hold the value of approriate ratio chosen.
 */
void equilibrium_a(int n, ratio *equilibrium)
{
	equilibrium->a = (n / SALARYLEVELS) + (n % SALARYLEVELS);
	equilibrium->b = n / SALARYLEVELS;
	equilibrium->c = n / SALARYLEVELS;
	printf ("[%d]:[%d]:[%d]\n", equilibrium->a, equilibrium->b,
			equilibrium->c);
}

/**
 * equilibrium_b - determins equillibrium whence [b]/Mid-Level Dev has the
 * highest number.
 * @n: the number of Devs needed for the project.
 * @equilibrium: varibale to hold the value of approriate ratio chosen.
 */
void equilibrium_b(int n, ratio *equilibrium)
{
	equilibrium->a = n / SALARYLEVELS;
	equilibrium->b = (n / SALARYLEVELS) + (n % SALARYLEVELS);
	equilibrium->c = n / SALARYLEVELS;
}

/**
 * equilibrium_c - determins equillibrium whence [c]/Junior Dev has the highest
 * number .
 * @n: the number of Devs needed for the project.
 * @equilibrium: varibale to hold the value of approriate ratio chosen.
 */
void equilibrium_c(int n, ratio *equilibrium)
{
	equilibrium->a = n / SALARYLEVELS;
	equilibrium->b = n / SALARYLEVELS;
	equilibrium->c = (n / SALARYLEVELS) + (n % SALARYLEVELS);
}

/**
 * equilibrium - establishes [a]:[b]:[c] as all equal.
 * Description: in use when n is divisible by SALARYLEVELS value without a
 * remainder.
 * @n: the number of Devs needed for the project.
 * @equilibrium: varibale to hold the value of approriate ratio chosen.
 */
void equilibrium(int n, ratio *equilibrium)
{
	equilibrium->a = n / SALARYLEVELS;
	equilibrium->b = n / SALARYLEVELS;
	equilibrium->c = n / SALARYLEVELS;
}
