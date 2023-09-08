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
	clearScreen();
	profession *newProf = NULL;
	int choice;

	do {
		newProf = create_field();
		list_init(head, newProf);
		printf("DO YOU WANT TO ADD TO THE DATABASE?\n");
		printf("--------------------------------------------------\n");
		printf("[1]. YES\n[2]. NOPE. TAKE ME BACK TO MAIN MENU\n");
		printf("--------------------------------------------------\n");
		printf("ENTER A CORRESONDING INDEX: ");
		scanf("%d", &choice);
	} while (choice != 2);
}

/**
 * rm_from_db - removes an item from the database
 * @db: the database we are deleting from.
 */
void rm_from_db(node **db)
{
	clearScreen();
	int tracker, entryNums, choice, entry;
	node *current = *db, *temp = NULL;

	if (*db == NULL)
	{
		printf("\nDATABASE IS EMPTY!\n");
		sleep(1);
		return;
	}
	display_db(db);
	printf("ENTER ITEM INDEX TO DELETE: ");
	scanf("%d", &choice);
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
	scanf("%d", &entry);
	if (entry == OFFONE)
		rm_from_db(db);
}
