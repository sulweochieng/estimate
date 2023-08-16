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
	return (0);
}
