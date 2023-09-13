#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * free_linked_list - a function that frees a linked list.
 * @head: pointer to the linked list to be freed.
 */
void free_list(node *head)
{
	node *temp = NULL;
	int i;

	while ( head != NULL)
	{
		temp = head;
		head = head->pointerNext;
		free(temp->data.name);
		for (i = 0; i < SALARYLEVELS; i++)
			free(temp->data.salaryLevels[i].level);
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
	int i;

	while (head != NULL)
	{
		temp = head;
		head = head->pointerNext;
		free(temp->info.name);
		free(temp->optLevel);
		for (i = 0; i < SALARYLEVELS; i++)
			free(temp->info.salaryLevels[i].level);
		free(temp);
	}
}
