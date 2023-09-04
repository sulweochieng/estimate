#include "../headers/main.h"
#include "../headers/fprtyps.h"
#include "../headers/types.h"

/**
 * equillibrium_compute - compute equillibrium cost.
 * Description: the computation is dependent on two factors either if the #
 * of developers passed ae disible by the number of the salary levels or not.
 * @ratioS: determines the ratios values to be used for the computational
 * purposes.
 * @devNum: the number of developers to be involved in the project.
 * @projectName: project parsed for computation.
 * @projectCost: variable to store total cost of project after computation.
 * @levelIndex: the optimal level index required for the project.
 */
void equillibrium_compute(ratio *ratioS, int devNum, node *projectName, double
		*projectCost, int levelIndex)
{
	void (*ratio_func[COST_OPTIONS])(int, ratio *) = {optimum_a, optimum_b,
		optimum_c, equilibrium, equilibrium_a, equilibrium_b,
		equilibrium_c};
	devLevels level;
	int eqChoice;

	if (!(devNum % SALARYLEVELS == 0))
	{
		print_levels(&level);
		scanf("%d", &eqChoice);
		ratio_func[eqChoice + 3](devNum, ratioS);
		node_cost_update(projectName, ratioS, projectCost);
	}
	else
	{
		ratio_func[levelIndex - 1](devNum, ratioS);
		node_cost_update(projectName, ratioS, projectCost);
	}
}
