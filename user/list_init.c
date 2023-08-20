#include "../headers/main.h"
#include "../headers/fprtyps.h"
#include "../headers/types.h"

/**
 * list_init - initiates a list.
 * Description: if linked list parsed doesn't exist, the function will create
 * it, and if the linked list parsed exist, the function will add a node to it.
 * @listName: the list to be created or appended to.
 */
void list_init(node *listName)
{
	profession *newProf = NULL;
	node newNode = NULL;
	node *devList = NULL;

	if (listName == NULL)
	{
		newProf = create_field();
		newNode = new_node(newProf);
		devList = create_list(newNode);
	}
	else
	{
		newProf = create_field();
		newNode = new_node(newProf);
		add_beg_list(&devList, newNode);
	}
}
