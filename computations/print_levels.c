#include "../headers/main.h"
#include "../headers/fprtyps.h"
#include "../headers/types.h"
/**
 * print_levels -  printd to stdout professional levels.
 * @levels: a struct type holding levels descriptions.
 */
void print_levels(devLevels *levels)
{
	init_levels(levels);
	printf("WHAT LEVEL OF EXPERTISE DO YOU WANT MORE?\n");
	printf("==========================================================\n");
	printf("[1]. %s\n", levels->a);
	printf("[2]. %s\n", levels->b);
	printf("[3]. %s\n", levels->c);
	printf("==========================================================\n");
	printf("Please enter the corresponding Index below and press ENTER\n");
}
