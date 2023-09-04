#ifndef TYPES_H
#define TYPES_H

/**
 * struct salaries - outlines salaries for the availbale proficiency levels.
 * @senior: senior developer's salary.
 * @midLevel: mid-level developer's salary.
 * @junior: junior developer's salary.
 */
typedef struct salaries
{
	double senior;
	double midLevel;
	double junior;
} sal;

/**
 * struct devLevels - defines different experience levels.
 * @a: represnts the highest level.
 * @b: represents the mid level.
 * @c: represents the junior level.
 */
typedef struct devLevels
{
	char *a;
	char *b;
	char *c;

} devLevels;
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
	salaryLevel salaryLevels[SALARYLEVELS];
} profession;

/**
 * struct node - a collective represantation of the list members.
 * @data: data bundle of a typical list member.
 * @pointerNext: pointer to the next member of the doubly linked list.
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
	struct node *heads[3];
} project;

/**
 * struct Ratio - a type that defines members of the ratio to be computed.
 * @a: first member.
 *	Represents the Senior level of expertise.
 * @b: second member.
 *	Represents the Mid-level level of expertise.
 * @c: third member.
 *	Represents the Junior level of expertise.
 */
typedef struct Ratio
{
	int a;
	int b;
	int c;
} ratio;

/**
 * struct Optimization - a type that gives descriptions to each optimazation
 * levels of the project.
 * @levelName: the name of optimization level.
 * @levelIntro: a short description of the optimization level.
 * @levelDescp: a short explainer of what the optLevel is. to give context to
 * the user.
 */
typedef struct Optimization
{
	char *levelName[OPTLEVELS];
	char *levelIntro[OPTLEVELS];
	char *levelDescp[OPTLEVELS];
} opt;

#endif
