#include "./headers/main.h"
#include "./headers/types.h"
#include "./headers/fprtyps.h"
#include "./headers/globals.h"

/**
 * main - my program's entry point.
 * Return: returns 0 on success.
 */
int main(void)
{
	void (*ratio_func[7])(int, ratio*) = {optimumA, optimumB, optimumC,
		equilibrium, equilibriumA, equilibriumB, equilibriumC};
	int n, select, i, k, eq;
	opt optLevels[4];
	double cost[3] = {3000, 2000, 1000};
	double pCost = 0.0;
	ratio ratioS;
	/*unsigned long int count;*/
	/*ratio ratioList[100];*/
	char *optimizationLevel[4] = {"Optimum", "Sub-Optimal", "Basic",
		"Equillibrium"};
	char *optIntro[4] = {"Highest level of optimization", "Inter-mediate\
		level of optimization", "Basic level of optimization",
		      "Balanced level of optimization"};
	char *optDesc[4] = {"The level provides a ratio wherein the value for\
		the Senior Dev is the highest. Advised for Projects HIGHEST\
			level of professionalism is required. It will involve\
			the highest cost.", "The level provides a ratio where\
			the the value for the Mid-Level Dev is the highest.\
			Advised for projects where time is of essence.", "The\
			level provides a ratio where the value for the Junior\
			Dev is the highest. Advised for projects where cost of\
			production is of esence.", "The level provides a ratio\
			wherein the values for Senior, Mid-level, and Junior\
			Devs are equal or close to equal."};

	for (i = 0; i < 4; i++)
	{
		optLevels[i].optLevel = strdup(optimizationLevel[i]);
		optLevels[i].intro = strdup(optIntro[i]);
		optLevels[i].description = strdup(optDesc[i]);
	}
	printf("How many AI/ML Devs do you want for the project?\n");
	scanf("%d", &n);
	printf("What OPTIMUM LEVEL ? Enter corresponding number\n");
	printf("\nFor reference below are the OPTIMUM LEVELS\n");
	printf("=========================================\n");
	for (k = 0; k < 4; k++)
		printf("[%d]: %s\n", k + 1,  optLevels[k].optLevel);
	printf("=========================================\n");
	scanf("%d", &select);
	printf("You have selected %s \n", optLevels[select - 1].optLevel);
	if (select > 3)
	{
		if (!(n % 3 == 0))
		{
			printf("WHAT LEVEL OF EXPERTISE DO YOU WANT MORE?\n");
			printf(" 1. SENIOR DEVS\n");
			printf(" 2. MID-LEVEL DEVS\n");
			printf(" 3. JUNIOR DEVS\n");
			printf("Please enter the corresponding number: ");
			scanf("%d", &eq);
			ratio_func[eq + 3](n, &ratioS);
			pCost = ((ratioS.a) * cost[1]) + ((ratioS.b) * cost[2])
				+ ((ratioS.c) * cost[3]);
			printf("The Project will cost you: %lf\n", pCost);
		} 
		else
		{
			ratio_func[select - 1](n, &ratioS);
			pCost = ((ratioS.a) * cost[1]) + ((ratioS.b) * cost[2]) +
				((ratioS.c) * cost[3]);
			printf("The Project will cost you: %lf\n", pCost);
		}
	}
	/*generate_ratio_list(n, ratioList, &count);*/
	return (0);
}
