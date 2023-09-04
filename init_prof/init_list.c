#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * init_list - creates a list.
 * Description: If the list doesn't exist, the function creates the list,
 * if the list exist, the function inserts the new node data unto the list.
 * @head: the list to initialise.
 */
void create_list(node **head)
{
	profession *newProf = NULL;
	int choice;

	do {
		newProf = create_field();
		list_init(head, newProf);
		printf("DO YOU WANT TO ADD MORE TO LIST?\n");
		printf("--------------------------------------------------\n");
		printf("[1]. Yes\n[2]. Nop\n");
		printf("--------------------------------------------------\n");
		printf("ENTER A CORRESONDING INDEX: ");
		scanf("%d", &choice);
	} while (choice != 2);
}
