#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct SalaryLevel - describes salaries depending on experience level.
 * @level: level of professional experience.
 * @salary: amount to be paid per month depending on coresponding level.
 */
struct SalaryLevel
{
	char *level;
	int salary;
};
/**
 * s_level - Typedef for struct Salary_level
 */
typedef struct SalaryLevel s_level;

/**
 * struct field - a description of a specific profession
 * @name: specific name of the profession required
 * @s_class: salary to be paid to the domain as specific to level of expertise
 * @num_levels: total number of levels available
 */
struct Field
{
	char *name;
	int num_levels;
	s_level *s_class;
};
/**
 * field - Typedef for struct Field
 */
typedef struct Field field; 

/**
 * struct Project - a definition of the specific project to be undertaken
 * @pname: name of the project
 * @plist: a list of professionals needed for the project
 * @pnum: total number of people needed for the project
 */
struct Project
{
	char *pname;
	field *plist[3];
	int pnum;
};
/**
 * project - Typedef for struct Project
 */
typedef struct Project project;

/* A list of possible fields in Software Development Project */
/*char *devList[10] = {"Web Developer", "Blockchain Developers", "QA/Testers", \
	"DevOps Engineeers", "UI/UX Designers", "Security Experts", \
		"AI/ML Developers", "Database Developers", \
		"Mobile App Developers", "Full-stack Developers"};*/
/* A list of supported Projects */
/*char *S_projects[] = {"Software Development"};*/
extern char *levels[];

/**
 * struct fieldNode - Typedef to struct newNode
 * Description: a node representation of type field within a linked list.
 * @nodeData: data of types field to be added to the list.
 * @nextNode: pointer to the next node in the list.
 */
struct fieldNode
{
	field *nodeData;
	struct fieldNode *nextNode;
};

/**
 * fieldNode - Typedef for struct fieldNode
 */
typedef struct fieldNode fieldNode;

#endif
