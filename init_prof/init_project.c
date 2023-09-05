#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * create_project - creates a new project.
 * Description: a project is created by selecting a node to add to the project
 * list from the list database.
 * @database: the database to select the node from.
 * @project: the project to create.
 */
void create_project(node **database, node **project)
{
	node *selectedNode = *database, *projectNode = NULL;
	int index, tracker = 0, choice;

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
			projectNode = malloc(sizeof(node));
			if (!projectNode)
			{
				printf("Failed to allocate memory\n");
				exit(EXIT_FAILURE);
			}
			projectNode->data = selectedNode->data;
			projectNode->pointerNext = *project;
			*project = projectNode;
			tracker = 0;
		}
		printf("DO YOU WANT TO ADD TO PROJECT\n");
		printf("[1]. Yes\n[2]. No\n");
		printf("ENTER CHOICE: ");
		scanf("%d", &choice);
	} while (choice != 2);
}
/**
 * display_project - display members available in a project
 * @project: the project to be displayed.
 */
void display_project(node **project)
{
	node *temp = *project;
	int index = OFFONE;

	if (temp == NULL)
	{
		printf("Project list still empty\n");
	}
	else
	{
		printf("--------------------------------------------------\n");
		printf("The prject list has the following entries\n");
		printf("--------------------------------------------------\n");
		while (temp != NULL)
		{
			printf("[%d]. %s\n", index++, temp->data.name);
			temp = temp->pointerNext;
		}
		printf("--------------------------------------------------\n");
	}
}


/**
 * rm_from_project - removes a node from project list.
 * @project: the project to remove from.
 */
void rm_from_project(node **project)
{
	node *prev = NULL, *current = *project;
	int index, nodeIndex;

	if (*project == NULL)
	{
		printf("PROJECT LIST STILL EMPTY. NOTHING TO DELETE\n");
		return;
	}
	display_project(project);
	printf("Which Professional do you want to delete from project: ");
	scanf("%d", &index);
	if (index == OFFONE)
	{
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
		prev->pointerNext = current->pointerNext;
		free(current);
		current = NULL;
		printf("Profession removed successfully\n");
	}
	printf("Do you want to remove another profession? (1: Yes, 2: No): ");
	scanf("%d", &index);
	if (index == 1)
		rm_from_project(project);
}
