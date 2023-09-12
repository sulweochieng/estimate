#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * create_project - creates a new project.
 * Description: a project is created by selecting a node to add to the project
 * list from the list database.
 * @database: the database to select the node from.
 * @project: the project to create.
 * @projectCost: computes project cost on every database entry.
 * @devNum: tracks number of professionals/node units for the whole project.
 */
void create_project(node **database, proj **project, double *projectCost, int
		*devNum)
{
	clearScreen();
	node *selectedNode = *database;
	proj *projectNode = NULL;
	int index, choice, tracker = 0;

	if (!(*database))
	{
		printf("DATABASE IS EMPTY\n");
		return;
	}
	do {
		display_db(database);
		printf("ENTER A CORRESPONDING INDEX TO ADD TO PROJECT: ");
		scanf("%d", &index);
		while (selectedNode != NULL)
		{
			tracker++;
			if (tracker == index)
				break;
			selectedNode = selectedNode->pointerNext;
		}
		if (selectedNode != NULL)
		{
			nod_assign(project, &selectedNode, &projectNode,
					projectCost, devNum, &tracker);
		}
		printf("[1].ADD TO PROJECT\n[2].BACK TO MENU\nENTER INDEX:");
		scanf("%d", &choice);
	} while (choice != 2);
	free(projectNode);
}

/**
 * nod_assign - updates the inticacies of the project node.
 * @project: the project to add the new node to.
 * @selectedNode: node from the main database.
 * @projectNode: the node to update.
 * @projectCost: updates the overall project cost on very node addition.
 * @devNum: tracks the total number of professionals added unto the project,
 * with their ratios.
 * @tracker: is set back to 0 on every addition to avoid double entry.
 */
void nod_assign(proj **project, node **selectedNode, proj **projectNode, double
		*projectCost, int *devNum, int *tracker)
{
	if (!(is_node_in_project(*project, *selectedNode)))
	{
		*projectNode = malloc(sizeof(proj));
		if (!*projectNode)
			exit(EXIT_FAILURE);
		(*projectNode)->info = (*selectedNode)->data;
		(*projectNode)->computed = FALSE;
		(*projectNode)->pointerNext = *project;
		*project = *projectNode;
		project_cost_calc(project, projectCost, devNum);
		*tracker = 0;
		printf("%s SUCCESSFULLY ADDED\n", (*project)->info.name);
	}
	else
	{
		printf("%s EXISTS IN PROJECT\n", (*selectedNode)->data.name);
	}
}
/**
 * display_project - display members available in a project
 * @project: the project to be displayed.
 */
void display_project(proj **project)
{
	clearScreen();
	proj *temp = *project;
	int index = OFFONE, i;

	if (temp == NULL)
	{
		printf("PROJECT LIST IS STILL EMPTY\n");
	}
	else
	{
		printf("--------------------------------------------------\n");
		printf("PROJECT DATABASE ENTRIE(S)\n");
		printf("--------------------------------------------------\n");
		while (temp != NULL)
			printf("[%d]. %s\n", index++, temp->info.name);
		printf("--------------------------------------------------\n");
	}
}


/**
 * rm_from_project - removes a node from project list.
 * @project: the project to remove from.
 * @projectCost: needs to be updated on every deletion.
 */
void rm_from_project(proj **project, double *projectCost)
{
	clearScreen();
	proj *prev = NULL, *current = *project;
	int index, nodeIndex, choice;

	if (*project == NULL)
	{
		printf("Nothing to DELETE!! Project database is EMPTY!!\n");
		return;
	}
	display_project(project);
	printf("ENTER CORRESPONDING INDEX TO DELETE: ");
	scanf("%d", &index);
	if (index == OFFONE)
	{
		*projectCost = project_cost_reduce(&current, projectCost);
		*project = current->pointerNext;
		free(current);
		printf("Profession removed successfully\n");
	}
	else
	{
		nodeIndex = OFFONE;
		while (nodeIndex != index)
		{

			prev = current;
			current = current->pointerNext;
			nodeIndex++;
		}
		*projectCost = project_cost_reduce(&current, projectCost);
		prev->pointerNext = current->pointerNext;
		free(current);
		current = NULL;
		printf("Profession removed successfully\n");
	}
	printf("DO YOU WANT TO REMOVE ANOTHER PROFESSION\n1: YES\n2: BACK\n");
	printf("OPTION: ");
	scanf("%d", &choice);
	if (choice == OFFONE)
		rm_from_project(project, projectCost);
}

/**
 * is_node_in_project - checks if a node already exists in the project.
 * @project: the project database.
 * @selectedNode: the new node to be added.
 * Return: returns true if it exist, or false if it deosn't exist.
 */
bool is_node_in_project(proj *project, node *selectedNode)
{
	while (project != NULL)
	{
		if (strcmp(project->info.name, selectedNode->data.name) == 0)
		{
			return (true);
		}
		project = project->pointerNext;
	}
	return (false);
}
