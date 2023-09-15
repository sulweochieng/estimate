#include "./headers/main.h"
#include "./headers/types.h"
#include "./headers/fprtyps.h"

/**
 * main - my program's entry point.
 * Return: returns 0 on success.
 */
int main(void)
{
	int action, devNum = 0, months = 0, menuSize = COSTOPTIONS;
	double projectCost = 0.0, tProjectCost;
	node *database = NULL;
	proj *project = NULL;
	char *menu[COSTOPTIONS] = {"CREATE/UPDATE DATABASE",
		"CREATE/UPDATE PROJECT", "DELETE ITEM FROM PROJECT",
		"GENERATE PROJECT DETAILS", "DISPLAY DATABASE",
		"DELETE FROM DB", "EXIT"};

	init_func(&database, &project, &projectCost, &devNum,
			&tProjectCost, &months, &action, menu, menuSize);
	printf("===========================================================\n");
	printf("THANK YOU!\n");
	sleep(1);
	printf("SYSTEM SHUTING DOWN NOW!\n");
	sleep(1);
	free_proj(project);
	free_list(database);
	return (0);
}

/**
 * init_func - initialises the program.
 * @action: represent the menu index to execute.
 * @database: the main project database.
 * @project: the project database.
 * @projectCost: the monthly project cost.
 * @devNum: number of professionals in the project.
 * @tProjectCost: the overall project cost computed with timeline.
 * @months: the project timeline.
 * @menu: menu icons.
 * @menuSize: the menu items.
 */
void init_func(node **database, proj **project, double *projectCost, int
		*devNum, double *tProjectCost, int *months, int *action, char
		*menu[], int menuSize)
{
	int i;

	clearScreen();
	salut();
	printf("\n\tWELCOME TO ESTIMATOR. A SIMPLE ESTIMATION TOOL\n");
	printf("===========================================================\n");
	do {
		printf("        ESTIMATE MENU\n");
		printf("--------------------------------------------------\n");
		for (i = FIRSTITEM; i < menuSize; i++)
			printf("[%d]. %s\n", i + OFFONE, menu[i]);
		printf("==================================================\n");
		choice_check(action, 7);
		switch (*action)
		{
			case 1:
				create_database(database);
				break;
			case 2:
				create_project(database, project,
						projectCost, devNum);
				project_sum(projectCost, tProjectCost,
						months);
				break;
			case 3:
				rm_from_project(project, projectCost, devNum,
						months, tProjectCost);
				break;
			case 4:
				display_project_details(project, projectCost,
						devNum, months, tProjectCost);
				break;
			case 5:
				display_db(database);
				break;
			case 6:
				rm_from_db(database);
				break;
		}
	} while (*action != 7);
}
