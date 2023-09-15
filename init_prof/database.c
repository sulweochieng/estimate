#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * create_database - creates a list.
 * Description: If the list doesn't exist, the function creates the list,
 * if the list exist, the function inserts the new node data unto the list.
 * @head: the list to initialise.
 */
void create_database(node **head)
{
	profession *newProf = NULL;
	int choice;

	clearScreen();
	do {
		newProf = malloc(sizeof(profession));
		if (!newProf)
		{
			printf("Memory allocation failure\n");
			exit(EXIT_FAILURE);
		}
		newProf->name = malloc(sizeof(char) * DEVSIZE);
		if (!(newProf->name))
		{
			printf("Memory Allocation failure\n");
			exit(EXIT_FAILURE);
		}
		create_field(head, &newProf);
		list_init(head, &newProf);
		printf("--------------------------------------------------\n");
		printf("[1].ADD TO DATABASE\n[2].BACK TO MAIN MENU\n");
		printf("--------------------------------------------------\n");
		choice_check(&choice, 2);
	} while (choice != 2);
}

/**
 * rm_from_db - removes an item from the database
 * @db: the database we are deleting from.
 */
void rm_from_db(node **db)
{
	int tracker, choice, entry, dbSize;
	node *current = *db, *temp = NULL;

	clearScreen();
	if (*db == NULL)
	{
		printf("\nDATABASE IS EMPTY!\n");
		sleep(1);
		return;
	}
	display_db(db);
	printf("ENTER ITEM INDEX TO DELETE: ");
	dbSize = node_count(db);
	choice_check(&choice, dbSize);
	if (choice == OFFONE)
	{
		*db = current->pointerNext;
		free(current);
		printf("ITEM DELETED SUCCESSFULY\n");
	}
	else
	{
		tracker = OFFONE;
		while (tracker != choice)
		{
			temp = current;
			current = current->pointerNext;
			tracker++;
		}
		temp->pointerNext = current->pointerNext;
		free(current);
		printf("ITEM DELETED SUCCESSFULLY\n");
	}
	printf("[1].DELETE ANOTHER\n[2]. BACK TO MAIN MENU\nINDEX: ");
	choice_check(&entry, 2);
	if (entry == OFFONE)
		rm_from_db(db);
}

/**
 * delete_item_select - selects from the project databae an item index to
 * delete.
 * @project: the project database we are deleting from.
 * @index: index at which we are deleting the profession from.
 */
void delete_item_select(proj **project, int *index)
{
	int projSize;

	display_project(project);
	printf("ENTER CORRESPONDING INDEX TO DELETE: ");
	projSize = proj_count(project);
	choice_check(index, projSize);
}
