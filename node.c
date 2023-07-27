#include "header.h"
#include "prtype.h"

fieldNode *create_node(field *newData)
{
	fieldNode *newNode;

	newNode = malloc(sizeof(fieldNode));
	if (!newNode)
	{
		printf("Failed to allocate memory\n");
		exit (EXIT_FAILURE);
	}
	newNode->nodeData = newData;
	newNode->nextNode = NULL;
	return (newNode);
}

fieldNode *create_new_list(void)
{
	char response[4];
	field *new_field = NULL;
	fieldNode *new_node = NULL;
	fieldNode *head = NULL;

	new_field = create_newField();
	new_node = create_node(new_field);
	head = malloc(sizeof(fieldNode));
	if (!head)
	{
		printf("Failed to allocate merory\n");
		exit (EXIT_FAILURE);
	}
	if (head == NULL)
		head = new_node;
	head = add_node_last(head, new_node); 
	printf("Do you want to add another FIELD to this LIST? (yes/no)\n");
	scanf("%s", response);
	if (strcmp(response, "yes") == 0)
	{
		new_node->nextNode = create_new_list();
	}
	else if (strcmp(response, "no") != 0)
	{
		printf("Invalid input. Please enter 'yes' or 'no'.\n");
	}
	else
	{
		return (head);
	}

	return (head);
}

fieldNode *add_node_last(fieldNode *head, fieldNode *newNode)
{
	fieldNode *temp;

	if (head == NULL)
	{
		head = create_new_list();
		return (head);
	}
	temp = head;
	while (temp->nextNode != NULL)
		temp = temp->nextNode;
	temp->nextNode = newNode;
	newNode->nextNode = NULL;
	printf("SUCCESFULLY ADDED TO THE END OF LIST\n");
	return (head);
}

fieldNode *add_node_beginning(fieldNode *head, fieldNode *newNode)
{

	if (head == NULL)
	{
		head = create_new_list();
		return (head);
	}
	newNode->nextNode = head;
	head = newNode;
	printf("ADDED AT THE BEGINNING SUCCESSFULLY\n");
	return (head);
}

void printList(fieldNode *head)
{
	fieldNode *current = NULL;
	int counter = 0;

	current = head;
	if (current == NULL)
	{
		printf("The parsed list is EMPTY\n");
		exit (EXIT_SUCCESS);
	}
	while (current != NULL)
	{
		counter++;
		current = current->nextNode;
	}
	printf("We have %d fields in the list\n", counter);
}
