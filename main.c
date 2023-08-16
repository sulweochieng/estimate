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
	int n, i;
	unsigned long int count;
	ratio ratioList[100];
	char *optimizationLevel[4] = {"Optimum", "Sub-Optimal", "Basic",
		"Equillibrium"};
	char *optIntro[4] = {"Highest level of optimization" , "Inter-mediate\
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

	printf("How many AI/ML Devs do you want for the project?\n");
	scanf("%d", &n);
	generate_ratio_list(n, ratioList, &count);
	printf("These are the possible ratios we can have for %d AI/ML Devs.\n",
			n);
	printf("==========================================================\n");
	for (i = 0; i < count; i++)
	{
		printf("Ratio[%d] => %d:%d:%d\n", i + 1, ratioList[i].a,
				ratioList[i].b, ratioList[i].c);
	}
	printf("%s\n", optDesc[2]);
	return (0);
}
