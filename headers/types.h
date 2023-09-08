#ifndef TYPES_H
#define TYPES_H

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
 * struct salaries - outlines salaries for the available proficiency levels.
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
 * Description: the project type differs from the node type by the introduction
 * of the computed member.
 * @info: holds the usual professional type info to be included in the project,
 * all copied from the type node, of the database.
 * @computed: set to false initially, to indicate that every newly added
 * profeesion type added to the list is not yet computed. This keeps track of
 * every computed member so as to prevent multiple computations in between
 * function calls.
 * @nodeRatio: tracks the ration to which nodecost was achieved.
 * @num: the number of ->info.name needed for the project.
 * @nodeCost: cost computed by referencing optLevel and nodeRatio.
 * @optLevel: Describes the optimization level for the ->info.name needed for
 * this particular project.
 * @pointerNext: points to the next node in the linked list.
 */
typedef struct Project
{
	profession info;
	int computed;
	ratio nodeRatio;
	int num;
	double nodeCost;
	char *optLevel;
	struct Project *pointerNext;
} proj;

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
