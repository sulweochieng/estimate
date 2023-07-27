#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "header.h"


void clear_input_buffer(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF);
}

field *create_newField(void)
{
	field *new = NULL;
	int i, j, c;
	char newField[100];
	char *levels[] = {"Junior", "Mid-level", "Senior"};

	new = malloc(sizeof(field));
	if (!new)
	{
		printf("Failed to allocate memory");
		exit (EXIT_FAILURE);
	}
	/* Getting user input for the new field */
	printf("Enter a new field you want to create and press ENTER: ");
	if (fgets(newField, sizeof(newField), stdin) != NULL)
	{
		/* Removing trailling newline character */
		newField[strcspn(newField, "\n")] = '\0';

		/* duplicating input into the name member*/
		new->name = strdup(newField);
		if (!new->name)
		{
			printf("Memory allocation FAILED!!\n");
			free(new);
			exit (EXIT_FAILURE);
		}
	}
	else 
	{
		printf("Error while reading input.\n");
		free(new);
		exit (EXIT_FAILURE);
	}
	new->num_levels = 3;
	new->s_class = malloc(sizeof(s_level) * new->num_levels);
	if (!new->s_class)
	{
		printf("Failed to allocate memory\n");
		free(new->name);
		free(new);
		exit (EXIT_FAILURE);
	}
	for (i = 0; i < new->num_levels; i++)
	{
		new->s_class[i].level = strdup(levels[i]);
		if (!new->s_class[i].level)
		{
			for (j = 0; j < new->num_levels; j++)
				free(new->s_class[i].level);
			free(new->s_class);
			free(new->name);
			free(new);
			printf("Couldn't allocate memory for %s \n",
					new->s_class[i].level);
			exit (EXIT_FAILURE);
		}

		printf("Enter %s %s's Salary: ", new->s_class[i].level, new->name);
		scanf("%d", (&(new->s_class[i].salary)));

		/* Clear input buffer after scanf to avoid issues with \n */
		clear_input_buffer();
	}
	return (new);
}
