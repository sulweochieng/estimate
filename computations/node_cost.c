#include "../headers/main.h"
#include "../headers/fprtyps.h"
#include "../headers/types.h"

/**
 * node_cost_update - computes total project cost.
 * Description: traverses the parsed lninked list computing cost per every
 * available node available in the linked list, at the end, updates the overall
 * project cost.
 * @project: the node we will be traversing.
 * @ratioS: established what ratios used in the computationals.
 * @projectCost: the overall project cost to be updated once all the
 * computations have been completed.
 */
void node_cost_update(node **project, ratio *ratioS, double *projectCost)
{
	node *temp = *project;
	double nodeCost, totalNodeCost = 0.0;

	while (temp != NULL)
	{
		nodeCost = ((ratioS->a) *
				(temp->data.salaryLevels[0].salary)) +
			((ratioS->b) * (temp->data.salaryLevels[1].salary)) +
			((ratioS->c) * (temp->data.salaryLevels[2].salary));
		totalNodeCost += nodeCost;
		temp = temp->pointerNext;
	}
	*projectCost = totalNodeCost;
	printf("=========================================\n");
	printf("The Project will cost you: %.2lf\n", *projectCost);
	printf("=========================================\n");
}
