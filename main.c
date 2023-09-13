#include "./headers/main.h"
#include "./headers/types.h"
#include "./headers/fprtyps.h"

/**
 * main - my program's entry point.
 * Return: returns 0 on success.
 */
int main(void)
{
	int action, i, devNum = 0, months = 0;
	double projectCost = 0.0, tProjectCost;
	node *database = NULL;
	proj *project = NULL;
	char *menu[COSTOPTIONS] = {"CREATE/UPDATE DATABASE",
		"CREATE/UPDATE PROJECT", "DELETE ITEM FROM PROJECT",
		"GENERATE PROJECT DETAILS", "DISPLAY DATABASE",
		"DELETE FROM DB", "EXIT"};

	clearScreen();
	salut();
	printf("\n\tWELCOME TO ESTIMATOR. A SIMPLE ESTIMATION TOOL\n");
	printf("===========================================================\n");
	do {
		printf("--------------------------------------------------\n");
		printf("        ESTIMATE MENU\n");
		printf("--------------------------------------------------\n");
		for (i = FIRSTITEM; i < COSTOPTIONS; i++)
			printf("[%d]. %s\n", i + OFFONE, menu[i]);
		printf("==================================================\n");
		choice_check(&action, 7);
		switch (action)
		{
			case 1:
				create_database(&database);
				break;
			case 2:
				create_project(&database, &project,
						&projectCost, &devNum);
				project_sum(&projectCost, &tProjectCost,
						&months);
				break;
			case 3:
				rm_from_project(&project, &projectCost, &devNum,
						&months, &tProjectCost);
				break;
			case 4:
				display_project_details(&project, &projectCost,
						&devNum, &months, &tProjectCost);
				break;
			case 5:
				display_db(&database);
				break;
			case 6:
				rm_from_db(&database);
				break;
			default:
				if (action < 0 || action > 7)
				{
					printf("PLEASE ENTER A VALID INDEX\n");
					break;
				}
		}
	} while (action != 7);
	printf("===========================================================\n");
	printf("THANK YOU!\n");
	sleep(1);
	printf("SYSTEM SHUTING DOWN NOW!\n");
	sleep(1);
	free_proj(poject);
	free_list(database);
	return (0);
}
