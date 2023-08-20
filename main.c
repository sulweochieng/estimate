#include "./headers/main.h"
#include "./headers/types.h"
#include "./headers/fprtyps.h"

/**
 * main - my program's entry point.
 * Return: returns 0 on success.
 */
int main(void)
{
	node *projectName
	double projectCost = 0.0;

	list_init(projectName);
	projectCostCalc(projectName, &projectCost)
	return (0);
}
