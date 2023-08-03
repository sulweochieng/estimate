#include "main.h"
#include "types.h"

/**
 * create_field - populatesalaryLevelss type Profession with appropriate data
 * Description: create_field function is designed to help the user create a new
 *	field under the type Profession. This new field is used within the
 *	system for various computational works; ranging from total project cost
 *	computed from the salary leves of every field used within a project.
 * Return: returns a pointer to the location of the newly created field.
 */
Profession *create_field(void)
{
	int i;
	Profession *newfield = NULL;
	static char *levels[3] = {"Junior", "Mid-level", "Senior"};
	int levels = SALARYLEVELS;
	int _salary;

	newfield = malloc(sizeof(Profession));
	if (!newfield)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	/* take input from the user to create a new field */
	printf("Please enter the NAME of the new FIELD to create: ");
	newfield->name = user_inputS();
	newfield->salaryLevels = malloc(sizeof(salaryLevel) * levels);
	if (!newfield->salaryLevels)
	{
		free(newfield->name);
		free(newfield);
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < levels; i++)
	{
		newfield->salaryLevels[i].level = strdup(levels[i]);
		printf("Please ENTER salary for a %s %s\n",
				newfield->salaryLevels[i].level,
				newfield->name);
		scanf("%d", &_salary);
		newfield->salaryLevels[i].level.salary = _salary;
	}
	return (newfield);
}

/**
 * create_node - a function that creates a new node for my linked list.
 * @pointer: a pointer to type profession variable .
 * Return: returns pointer to the new node created.
 */
node *new_node(Profession *pointer)
{
	node *new = NULL;

	new = malloc(sizeof(node));
	if (!new)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	new->data = pointer;
	new->pointerNext = NULL;
	return (new);
}

/**
 * create_list - a funtion creating a new linked list.
 * @new: a data node to be added into the list
 * Return: returns pointer to the head of the newly created list.
 */
node *create_list(node *new)
{
	node *head = NULL;

	head = malloc(sizeof(node));
	if (!head)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	head->data = new;
	head->pointerNext = NULL;

	return (head);
}

/**
 * add_beg_list - adds a new node to the list at the the beginning of the list.
 * @node: the node to be added to the list.
 * @head: pointer to the list to which we are adding the node unto.
 */
void add_beg_list(node **head, node *node)
{
	node *temp = NULL;

	temp = *head;
	*head = node;
	*head->pointerNext = temp;
	printf("Node %s was added succesfully at the begining of list!\n",
			head->data.name);
	temp = NULL;
	node = NULL;
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
		printf("The list %s is empty\n");
		exit(EXIT_SUCCESS);
	}
	while (temp != NULL)
	{
		temp = temp->pointerNext;
		counter++;
	}
	return (counter);
}
