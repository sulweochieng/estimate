#ifndef TYPES_H
#define TYPES_H

/**
 * struct salaryLevel - defines how different experience levels are paid.
 * @level: defines a specific proficiency level.
 * @salary: defines the exact amount to be paid to the corelating level.
 */
typedef struct salaryLevel
{
	char *level;
	double  salary;
} salaryLevel;

/**
 * struct Profession - blueprint of a profession by name and various
 * salaryLevels.
 * @name: the specific identity of the profession.
 * @salaryLevels: description of pay per salary level of each proficiency level
 * available.
 */
typedef struct Profession
{
	char *name;
	salaryLevel *salaryLevels;
} profession;

/**
 * struct node - a collective represantation of the list members.
 * @data: data bundle of a typical list member.
 * @pointerNext: pointer to the next member list.
 */
typedef struct node
{
	profession data;
	struct node *pointerNext;
} node;

/**
 * struct Project - an identifier for a project.
 * Description: the project type holds *head of different professions needed
 * in a specific project descritption. It will also have a name member which
 * will be used to identify the soecific project the client/user is working on.
 * @heads: an array of heads, typically a classification of various related
 * professions/professionals.
 *	head represents a whole classification of closely related professions.
 *	We can also refer to them as fields.
 * @name: to indicate the name of the project the user is working on. Specific
 * as posible.
 */
typedef struct Project
{
	char *name;
	struct node *heads[];
} project;

#endif