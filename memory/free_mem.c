#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"
#include "../headers/globals.h"

/**
 * free_linked_list - a function that frees a linked list.
 * @head: pointer to the linked list to be freed.
 */
void free_list(node *head)
{
	node *temp = NULL;

	temp = head;
	head = head->pointerNext;
	free(temp->data.name);
	free(temp);
}
