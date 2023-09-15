#include "../headers/main.h"
#include "../headers/fprtyps.h"
#include "../headers/types.h"

/**
 * project_cost_calc - calculates the total project cost.
 * @projectName: type node pointing to selcted items from type node devList.
 * @projectCost: variable holding the total project cost.
 * @profNum: number of professionals involved in the project.
 */
void project_cost_calc(proj **projectName, double *projectCost, int *profNum)
{
	void (*ratio_func[COSTOPTIONS])(int, ratio *) = {optimum_a, optimum_b,
		optimum_c, equilibrium, equilibrium_a, equilibrium_b,
		equilibrium_c};
	opt optInfo;
	ratio ratioS;
	int devNum, levIndex;
	proj *current = *projectName;

	clearScreen();
	while (current != NULL)
	{
		if (current->computed == FALSE)
		{
			printf("How many %sS do you want for this project: ",
					current->info.name);
			scanf("%d", &devNum);
			current->num = devNum;
			*profNum = prof_num(projectName, profNum, devNum);
			levIndex = opt_info_set(&current, &optInfo);
			if (levIndex > OPTIMUM)
			{
				equillibrium_compute(&ratioS, &devNum,
						&levIndex);
				current->nodeRatio = ratioS;
				current->nodeCost =
					node_cost_update(projectName, &ratioS);
			}
			else
			{
				ratio_func[levIndex - OFFONE](devNum, &ratioS);
				current->nodeRatio = ratioS;
				current->nodeCost =
					node_cost_update(projectName, &ratioS);
			}
		}
		*projectCost = project_costing(&current, projectCost);
		current->computed = TRUE;
		current = current->pointerNext;
	}
}

/**
 * opt_info_set - sets the optimization level needed for a specific profession
 * needed within the main project.
 * @projNode: the node/profession which is to be set.
 * @optInfo: optimaization level descriptions.
 * Return: returns the level of otimization chosen by the user.
 */
int opt_info_set(proj **projNode, opt *optInfo)
{
	int levIndex, j;

	printf("BELOW ARE THE CURRENT AVAILABLE OPTIMUM LEVELS\n");
	printf("----------------------------------------------------------\n");
	init_optimization_info(optInfo);
	for (j = 0; j < OPTLEVELS; j++)
		printf("[%d]. %s\n", j + 1, optInfo->levelName[j]);
	printf("----------------------------------------------------------\n");
	printf("PLEASE CHOOSE A LEVEL BY ENTERING A CORRESPONDING INDEX: ");
	choice_check(&levIndex, 4);
	(*projNode)->optLevel = strdup(optInfo->levelName[levIndex - OFFONE]);
	printf("----------------------------------------------------------\n");

	return (levIndex);
}

/**
 * project_cost_reduce - reduces the overral project cost on every node
 * deletion.
 * @projectNode: the specific node/item we are to delete.
 * @projectCost: the cost to be reduced.
 * Return: updated project cost.
 */
double project_cost_reduce(proj **projectNode, double *projectCost)
{
	double newCost;

	if (*projectNode != NULL)
		newCost = *projectCost - (*projectNode)->nodeCost;
	return (newCost);
}

/**
 * project_costing - produces/computes project cost.
 * @project: the project we are estimating its cost.
 * @projectCost: cost of the project to be computed.
 * Return: the new overall cost of the project.
 */
double project_costing(proj **project, double *projectCost)
{
	proj *current = *project;

	if (current == NULL)
	{
		*projectCost = 0.0;
		return (*projectCost);
	}
	if (current->computed == FALSE)
	{
		clear_input_buffer();
		*projectCost += current->nodeCost;
	}
	return (*projectCost);
}

/**
 * prof_num - computes the number of professionals involved in a project.
 * Description: NOTE we are not counting the number of nodes, but computing
 * total number of involved professionals, dependent on the optimal level used.
 * @project: the project list to compute its total members.
 * @profNum: number of professionals to be updated.
 * @nodNum: number of a specific node/professional involved in the project.
 * Return: returns updated number of professionals involved in the project.
 */
int prof_num(proj **project, int *profNum, int nodNum)
{
	proj *current = *project;

	if (current == NULL)
	{
		*profNum = 0;
		return (*profNum);
	}
	if (current->computed == FALSE)
	{
		clear_input_buffer();
		*profNum += nodNum;
	}
	return (*profNum);
}
