#include "./headers/main.h"
#include "./headers/types.h"
#include "./headers/fprtyps.h"

/**
 * main - my program's entry point.
 * Return: returns 0 on success.
 */
int main(void)
{
	clearScreen();
	int action, i, devNum = 0;
	double projectCost = 0.0;
	node *database = NULL;
	proj *project = NULL;
	char *menu[COSTOPTIONS] = {"CREATE/UPDATE DATABASE",
		"CREATE/UPDATE PROJECT", "DELETE ITEM FROM PROJECT",
		"GENERATE PROJECT DETAILS", "DISPLAY DATABASE",
		"DELETE FROM DB", "EXIT"};

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
		printf("PLEASE ENTER A CORRESPONDING INDEX TO AN ACTION: ");
		scanf("%d", &action);
		switch (action)
		{
			case 1:
				create_database(&database);
				break;
			case 2:
				create_project(&database, &project,
						&projectCost, &devNum);
				break;
			case 3:
				rm_from_project(&project, &projectCost);
				break;
			case 4:
				display_project_details(&project, &projectCost,
						&devNum);
				break;
			case 5:
				display_db(&database);
				break;
			case 6:
				rm_from_db(&database);
				break;
			case 7:
				if (action < 1 || action > 6)
					printf("WRONG CHOICE! ENTER A VALID ONE\n");
				break;
		}
	} while (action != COSTOPTIONS + OFFONE);
	printf("===========================================================\n");
	printf("THANK YOU!\n");
	sleep(1);
	printf("SYSTEM SHUTING DOWN NOW!\n");
	sleep(1);
	return (0);
}
