#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * free_list - a function that frees a linked list.
 * @head: pointer to the linked list to be freed.
 */
void free_list(node *head)
{
	node *temp = NULL;

	while (head != NULL)
	{
		temp = head;
		head = head->pointerNext;
		free(temp);
	}
}

/**
 * free_proj - frees project list
 * @head: pointer to project.
 */
void free_proj(proj *head)
{
	proj *temp = NULL;

	while (head != NULL)
	{
		temp = head;
		head = head->pointerNext;
		free(temp->optLevel);
		free(temp);
	}
}
