#include "./headers/main.h"
#include "./headers/types.h"
#include "./headers/fprtyps.h"

/**
 * main - my program's entry point.
 * Return: returns 0 on success.
 */
int main(void)
{
	int choice;
	double projectCost = 0.0;

	printf("\nWELCOME TO ESTIMATOR. A SIMPLE ESTIMATION TOOL\n");
	printf("===========================================================\n");
	do {
		printf("PLEASE CHOOSE AN INDEX CORRESPONDING TO AN ACTION\n");
		1. remove item from list.
			a. reduce project
		2. print all names present in project.
		3. Prevent double entry of node item to list
		4. Compute project cost
		5. start new project
		5. exit function
		6. adjecent !> next
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				/*implement logic*/
				break;
			case 2:
				/*implement logic*/
				break;
			default:
				printf("Invalid choice.\n");
	} while (choice != value of exit);
	printf("===========================================================\n");
	printf("THANK YOU!");
	sleep(3);
	printf("SYSTEM SHUTING DOWN NOW\n");
	return (0);
}
