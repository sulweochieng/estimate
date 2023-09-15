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
	node *selectedNode = *database;
	proj *projectNode = NULL;
	int index, choice, tracker = 0, dbSize;

	clearScreen();
	if (!(*database))
	{
		printf("DATABASE IS EMPTY\n");
		return;
	}
	do {
		display_db(database);
		printf("ENTER A CORRESPONDING INDEX TO ADD TO PROJECT: ");
		dbSize = node_count(database);
		choice_check(&index, dbSize);
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
		printf("[1].ADD TO PROJECT\n[2].BACK TO MENU\n");
		choice_check(&choice, 2);
	} while (choice != 2);
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
	proj *temp = *project;
	int index = OFFONE;

	clearScreen();
	if (temp == NULL)
	{
		printf("PROJECT LIST IS STILL EMPTY\n");
		return;
	}
	else
	{
		printf("--------------------------------------------------\n");
		printf("PROJECT DATABASE ENTRIE(S)\n");
		printf("--------------------------------------------------\n");
		while (temp != NULL)
		{
			printf("[%d].%s\n", index++, temp->info.name);
			temp = temp->pointerNext;
		}
		printf("--------------------------------------------------\n");
	}
}


/**
 * rm_from_project - removes a node from project list.
 * @project: the project to remove from.
 * @projectCost: needs to be updated on every deletion.
 * @devNum: total number of developers involved in project.
 * @months: project duration.
 * @tProjectCost: overall project cost.
 */
void rm_from_project(proj **project, double *projectCost, int *devNum, int
		*months, double *tProjectCost)
{
	proj *prev = NULL, *current = *project;
	int index, nodeIndex, choice;

	clearScreen();
	if (*project == NULL)
	{
		printf("Nothing to DELETE!! Project database is EMPTY!!\n");
		return;
	}
	delete_item_select(project, &index);
	if (index == OFFONE)
	{
		*projectCost = project_cost_reduce(&current, projectCost);
		*devNum -= current->num;
		*project = current->pointerNext;
		free(current->optLevel);
		free(current);
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
		*devNum -= current->num;
		prev->pointerNext = current->pointerNext;
		free(current->optLevel);
		free(current);
	}
	printf("REMOVE ANOTHER?\n1: YES\n2: BACK\nOPTION: ");
	choice_check(&choice, 2);
	if (choice == OFFONE)
		rm_from_project(project, projectCost, devNum, months,
				tProjectCost);
	project_sum(projectCost, tProjectCost, months);
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
