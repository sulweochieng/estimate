#include "../headers/main.h"
#include "../headers/fprtyps.h"
#include "../headers/types.h"

/**
 * projectCostCalc - calculates the total project cost.
 * @projectName: type node pointing to selcted items from type node devList.
 * @projectCost: variable holding the total project cost.
 */
void project_cost_calc(node *projectName, double *projectCost)
{
	void (*ratio_func[COST_OPTIONS])(int, ratio *) = {optimumA, optimumB,
		optimumC, equilibrium, equilibriumA, equilibriumB,
		equilibribriumC};
	opt optInfo;
	ratio ratioS;
	int j, devNum, levIndex;

	printf("How many %s do you want for this project: ",
			projectName->data->name);
	scanf("%d", &devNum);
	printf("BELOW ARE THE CURRENT AVAILABLE OPTIMUM LEVELS\n");
	printf("----------------------------------------------------------\n");
	init_optimization_info(&optInfo);
	for (j = 0; j < OPTLEVELS; j++)
		printf("\n[%d]. %s\n", j + 1, optInfo.levelName[j]);
	printf("----------------------------------------------------------\n");
	printf("\nPLEASE CHOOSE A LEVEL BY ENTERING A CORRESPONDING INDEX: ");
	scanf("%s", &levIndex);
	printf("You've slected %s\n", optInfo.levelName[levelIndex - 1]);
	printf("%s\n", optInfo.levelIntro[levelIndex - 1]);
	printf("----------------------------------------------------------\n");
	if (levIndex > 3)
	{
		equillibrium_compute(&ratioS, devNum, projectName, projectCost,
				levelIndex);
	}
	else
	{
		ratio_func[levelIndex - 1](devNum, &ratioS);
		node_cost_update(projectName, &ratioS, projectCost);
	}
}
