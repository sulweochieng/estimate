#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"
#include "../headers/globals.h"

/**
 * create_field - populatesalaryLevelss type Profession with appropriate data
 * Description: create_field function is designed to help the user create a new
 *	field under the type Profession. This new field is used within the
 *	system for various computational works; ranging from total project cost
 *	computed from the salary leves of every field used within a project.
 * Return: returns a pointer to the location of the newly created field.
 */
profession *create_field(void)
{
	int i;
	profession *newfield = NULL;
	char *levels[3] = {"Junior", "Mid-level", "Senior"};
	double _salary;

	newfield = malloc(sizeof(profession));
	if (!newfield)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	printf("Please enter the NAME of the new FIELD to create: ");
	newfield->name = strdup(user_input_string());
	newfield->salaryLevels = malloc(sizeof(salaryLevel) * SALARYLEVELS);
	if (!newfield->salaryLevels)
	{
		free(newfield->name);
		free(newfield);
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < SALARYLEVELS; i++)
	{
		newfield->salaryLevels[i].level = strdup(levels[i]);
		printf("Please ENTER salary for a %s %s\n",
				newfield->salaryLevels[i].level,
				newfield->name);
		scanf("%lf", &_salary);
		newfield->salaryLevels[i].salary = _salary;
		newfield->salaryLevels[i].refCount = 1;
	}
	return (newfield);
}

/**
 * create_node - a function that creates a new node for my linked list.
 * @newData: pointer to type profession variable .
 * Return: returns pointer to the new node created.
 */
node *new_node(profession *newData)
{
	node *newNode = NULL;
	int i;

	newNode = malloc(sizeof(node));
	if (!newNode)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = newData;
	for (i = 0; i < SALARYLEVELS; i++)
		newData->salaryLevels[i].refCount++;
	newNode->pointerNext = NULL;
	return (newNode);
}

/**
 * create_list - a funtion creating a new linked list.
 * @newNode: a data node to be added into the list
 * Return: returns pointer to the head of the newly created list.
 */
node *create_list(node *newNode)
{
	node *head = NULL;

	head = malloc(sizeof(node));
	if (!head)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	head = newNode;
	newNode = NULL;

	return (head);
}

/**
 * add_beg_list - adds a new node to the list at the the beginning of the list.
 * @newNode: the node to be added to the list.
 * @head: pointer to the list to which we are adding the node unto.
 */
void add_beg_list(node **head, node *newNode)
{
	if (*head == NULL)
	{
		printf("The list was empty\n");
		*head = newNode;
		newNode->pointerNext = NULL;
		printf("Node %s was added successfully at the beginning\n"
				, (*head)->data->name);
	}
	newNode->pointerNext = *head;
	*head = newNode;
	printf("Node %s was added succesfully at the begining of list!\n",
			(*head)->data->name);
	newNode = NULL;
}

/**
 * node_count - counts the total number of items of the parsed linked list.
 * @head: the begining of the list to be counted.
 * Return: number of total number of nodes in the parsed list.
 */
unsigned int node_count(node *head)
{
	node *temp = NULL;
	unsigned int counter = 0;

	temp = head;
	if (head == NULL)
	{
		printf("The list is empty\n");
		exit(EXIT_SUCCESS);
	}
	while (temp != NULL)
	{
		temp = temp->pointerNext;
		counter++;
	}
	return (counter);
}
