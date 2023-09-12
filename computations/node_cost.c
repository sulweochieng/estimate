#include "../headers/main.h"
#include "../headers/fprtyps.h"
#include "../headers/types.h"

/**
 * node_cost_update - computes a specific node's cost.
 * @projectNode: the actual node to compute unit/node cost for.
 * @ratioS: established ratios used in the computationals.
 * Return: total node computational cost.
 */
double node_cost_update(proj **projectNode, ratio *ratioS)
{
	double nodeCost = 0.0;

	if ((*projectNode)->computed == FALSE && (*projectNode)->nodeCost == 0.0)
		unit_sum(projectNode, ratioS, &nodeCost);
	return (nodeCost);
}

/**
 * unit_sum - adds up all node member units.
 * @nod: the specific node to compute the sum.
 * @rat: the node's ration distribution.
 * @nCost: the cumulative node cost.
 */
void unit_sum(proj **nod, ratio *rat, double *nCost)
{
	*nCost = rat->a * (*nod)->info.salaryLevels[2].salary + rat->b *
		(*nod)->info.salaryLevels[1].salary + rat->c *
		(*nod)->info.salaryLevels[0].salary;
}

/**
 * display_project_details - displays every project detail after computation.
 * @project: the project to display information on.
 * @projectCost: the cost of the project.
 * @devNum: the total number of professionals involved in the project.
 */
void display_project_details(proj **project, double *projectCost, int *devNum)
{
	clearScreen();
	proj *temp = *project;
	int index = OFFONE, i;

	if (!temp)
		printf("NO ITEM IN PROJECT LIST YET\n");
	printf("--------------------------------------------------\n");
	printf("\tPROJECT DETAILED INFORMATION\n");
	printf("--------------------------------------------------\n");
	printf("MONTHLY PROJECT COST [%.2lf]\nTOTAL NUMBER OF PROFESSIONALS [%d]\n",
			*projectCost, *devNum);
	while (temp != NULL)
	{
		printf("==================================================\n");
		printf("[%d].%s | LEVEL = %s | NUMBER = %d |\n",
				index++, temp->info.name,
				temp->optLevel, temp->num);
		printf("==================================================\n");
		for (i = 0; i < SALARYLEVELS; i++)
		{
			printf("%s %s = %.2lf\n",
					temp->info.salaryLevels[i].level,
					temp->info.name,
					temp->info.salaryLevels[i].salary);
		}
		printf("\nUNIT COST IN PROJECT = %.2lf\n", temp->nodeCost);
		printf("PROFECIENCY LEVEL DISTRIBUTION\n");
		printf("------------------------------------------\n");
		printf("JUNIOR = %d\nMID-LEVEL = %d\nSENIOR = %d\n",
				temp->nodeRatio.c, temp->nodeRatio.b,
				temp->nodeRatio.a);
		temp = temp->pointerNext;
	}
	printf("--------------------------------------------------\n");
}
