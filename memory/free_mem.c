#include "./headers/main.h"
#include "./headers/types.h"
#include "./headers/fprtyps.h"
#include "./headers/globals.h"

/**
 * free_node_data - a function that frees all data assigned to a a node.
 */
void free_node_data(profession *newField)
{
	int i;
	/*free the salary level data */
	for (i = 0; i < SALARYLEVELS; i++)
	{
		free(newField->salaryLevels[i].level);
		newField->salaryLevels[i].level = NULL;
		free(newField->salaryLevels[i].salary);
		newField->salaryLevelsp[i].salary = NULL;
	}
	free(newField->salaryLevels);
	newField->salaryLevels = NULL;
	free(newField->name);
	newField->name = NULL;
	free(newField);
	newField = NULL;
}

/**
 * free_node - a function that frees all memory allocated to every node members
 * parsed to it.
 */
void free_node(node *newNode)
{
	free(newNode);
	newNode = NULL;
}
/**
 * free_linked_list - a function that frees a linked list.
 * @head: pointer to the linked list to be freed.
 */
void free_linked_list(node **head)
{
}
