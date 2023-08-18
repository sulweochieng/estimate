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
		printf("--------------------------------------------------\n");
		printf("Trying to free %s level\n",
				(*temp)->data->salaryLevels[i].level);
		printf("--------------------------------------------------\n");
		(*temp)->data->salaryLevels[i].refCount--;
		if ((*temp)->data->salaryLevels[i].refCount == 0)
		{
			free((*temp)->data->salaryLevels[i]);
			printf("Successfully free'd: %s level\n",
					(*temp)->data->salaryLevels[i].level);
			(*temp)->data->salaryLevels[i] = NULL;
		}
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
	node *current = NULL;
	node *temp = NULL;
	int i;

	current = *head;
	while (current != NULL)
	{
		temp = current;
		if (current->data != NULL)
		{
			for (i = 0; i < SALARYLEVELS; i++)
				free(current->data->salaryLevels[i]);
			free(current->data->salaryLevels);
			free(current->data->name);
			free(current->data);
		}
		current = current->pointerNext;
		free(temp);
	}
	*head = NULL;
}
