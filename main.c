#include "./headers/main.h"
#include "./headers/types.h"
#include "./headers/fprtyps.h"
#include "./headers/globals.h"

/**
 * main - my program's entry point.
 * Return: returns 0 on success.
 */
int main(void)
{
	int i;
	profession *newPerson = NULL;
	node *newNode = NULL;
	node *head = NULL;
	unsigned int nodeNumber;

	newPerson = create_field();
	newNode = new_node(newPerson);
	if (head == NULL)
		head = create_list(newNode);
	add_beg_list(&head, newNode);
	free_linked_list(&head);
	/**nodeNumber = node_count(head);
	printf("We have %d nodes in the list\n", nodeNumber);
	*/
	return (0);
}
