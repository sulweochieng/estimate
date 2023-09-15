#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * create_field - populatesalaryLevelss type Profession with appropriate data.
 * @db: the database to check for an entry
 * Description: create_field function is designed to help the user create a new
 *	field under the type Profession. This new field is used within the
 *	system for various computational works; ranging from total project cost
 *	computed from the salary leves of every field used within a project.
 * Return: returns a pointer to the location of the newly created field.
 */
void create_field(node **db, profession **newfield)
{
	int i;
	double levelSalary;
	char *levels[SALARYLEVELS] = {"JUNIOR", "MID-LEVEL", "SENIOR"};

	clear_input_buffer();
	user_input_string(db, &((*newfield)->name));
	for (i = FIRSTITEM; i < SALARYLEVELS; i++)
	{
		(*newfield)->salaryLevels[i].level = (levels[i]);
		printf("ENTER SALARY FOR %s %s: ",
				(*newfield)->salaryLevels[i].level,
				(*newfield)->name);
		scanf("%lf", &levelSalary);
		if (i > 0 && levelSalary <= (*newfield)->salaryLevels[i -
				OFFONE].salary)
		{
			printf("PLEASE INPUT VALUE GREATER THAN %s %s's salary\n",
					(*newfield)->salaryLevels[i - OFFONE].level,
					(*newfield)->name);
			--i;
		}
		else
		{
			(*newfield)->salaryLevels[i].salary = levelSalary;
		}
	}
}

/**
 * list_init - creates/initialises/appends to/inserts node(s) to a linked list.
 * @newData: pointer to type profession variable .
 * @head: pointer to the list we are to initialise.
 * Description: If list is empty, create list.
 * If list is not empty add node:
 *	at the biginning,
 *	at an index, or
 *	at the end of the list.
 */
void list_init(node **head, profession **newData)
{
	node *newNode = NULL;

	newNode = malloc(sizeof(node));
	if (!newNode)
	{
		printf("Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = **newData;
	free(*newData);
	newNode->pointerNext = *head;
	*head = newNode;
}

/**
 * node_count - counts the total number of items of the parsed linked list.
 * @head: the database to compute its entries.
 * Return: return the total number of items in the database.
 */
int node_count(node **head)
{
	int counter = 0;
	node *temp = NULL;

	temp = *head;
	if (*head == NULL)
	{
		printf("The database is empty\n");
		return (0);
	}
	while (temp != NULL)
	{
		temp = temp->pointerNext;
		++counter;
	}
	return (counter);
}

/**
 * proj_count - counts number of items in a project.
 * @head: project head node.
 * Return: number of items in the project.
 */
int proj_count(proj **head)
{
	int counter = 0;
	proj *temp = *head;

	if (temp == NULL)
	{
		printf("The project list is still empty\n");
		return (0);
	}
	while (temp != NULL)
	{
		++counter;
		temp = temp->pointerNext;
	}
	return (counter);
}

/**
 * display_db - prints the name of all professions available in the list.
 * @db: the database to print its data.
 */
void display_db(node **db)
{
	node *temp = *db;
	int i = OFFONE;

	if (temp == NULL)
		printf("The database is empty!!\n");
	printf("\tDATABASE ENTRIES\n");
	printf("==================================================\n");
	while (temp != NULL)
	{
		printf("[%d]. %s\n", i, temp->data.name);
		temp = temp->pointerNext;
		i++;
	}
}
