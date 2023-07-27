#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "prtype.h"

int main(void)
{
	/*field *new = NULL;
	int i, choice;
	fieldNode *new_node, *head = NULL;
	fieldNode *(*add_node[2])(fieldNode *, fieldNode *) = {add_node_last,
		add_node_beginning};
		*/

	/*new = create_newField();
	printf("\nHere is how %ss are payed according to WORK EXPERIENCE\n", new->name);
	printf("We currently ONLY have %d Work experience levels as listed below:\n", new->num_levels);
	printf("----------------------------------------------------------------\n\n");
	for (i = 0; i < new->num_levels; i++)
	{
		printf("%s %s is paid %d\n", new->s_class[i].level, new->name,
				new->s_class[i].salary);
	}
	printf("\n----------------------------------------------------------------\n");
	for (i = 0; i < new->num_levels; i++)
			free(new->s_class[i].level);

	new_node = create_node(new);
	printf("Where do you want to add the new FIELD to?\n");
	printf("ENTER '1' to add at the BEGINNING\n");
	printf("ENTER '2' to add at the END\n");
	scanf("%d", &choice);
	head = add_node[choice - 1](head, new_node);
	printList(head);
	*/
	fieldNode *head = NULL;

	head = create_new_list();
	printList(head);
	/*free(new->s_class);
	free(new->name);
	free(new);
	*/
	return (0);
}
