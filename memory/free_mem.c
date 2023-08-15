#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"
#include "../headers/globals.h"

/**
 * free_node - a function that frees all memory allocated to every node members
 * parsed to it.
 * @temp: pointer to the pointer used to move across the linked list.
 * Description: the function starts by freeing the node's data, then continues
 * to free the node itself
 */
void free_node(node **temp)
{
	int i;

	/* free node data before freeing the node*/
	for (i = 0; i < SALARYLEVELS; i++)
	{
		free((*temp)->data->salaryLevels[i].level);
		printf("Successfully free'd: %s level\n",
				(*temp)->data->salaryLevels[i].level);
		(*temp)->data->salaryLevels[i].level = NULL;
	}
	free((*temp)->data->salaryLevels);
	(*temp)->data->salaryLevels = NULL;
	free((*temp)->data->name);
	(*temp)->data->name = NULL;
	free((*temp)->data);
	(*temp)->data = NULL;
}
/**
 * free_linked_list - a function that frees a linked list.
 * @head: pointer to the linked list to be freed.
 */
void free_linked_list(node **head)
{
	node *temp = NULL;
	node *next = NULL;

	temp = *head;
	while (temp != NULL)
	{
		next = temp->pointerNext;
		free_node(&temp);
		temp = next;
	}
	*head = NULL;
}
