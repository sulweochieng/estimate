#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"

/**
 * init_optimization_info - initiates the optimization infomation.
 * @info: pointer to type opt that holds the optimization information.
 */
void init_optimization_info(opt *info)
{
	info->levelName[0] = "OPTIMUM";
	info->levelName[1] = "SUB-OPTIMAL";
	info->levelName[2] = "BASIC";
	info->levelName[3] = "EQUILLIBRIUM";

	info->levelIntro[0] =
		"Highest level of optimization, "
		"with number of Senior level professionals at highest.";
	info->levelIntro[1] =
		"Inter-mediate level of optimization, "
		"with number of Mid-level professionals at highest.";
	info->levelIntro[2] =
		"Basic level of optimization, "
		"with number of Junior level professionals at highest.";
	info->levelIntro[3] =
		"Balanced level of optimization, "
		"Aims to distribute the professional levels equally.";

	info->levelDescp[0] =
		"The level provides a ratio wherein the value for the Senior "
		"professionals is the highest."
		"Advised for Projects where number needed is below 5."
		"It might involve/produce the highest project cost.";
	info->levelDescp[1] =
		"The level provides a ratio where the  value/number of the "
		"Mid-Level proeffionals is the highest. "
		"Advised for projects where time is of essence, "
		"and the number needed is below 5.";
	info->levelDescp[2] =
		"The level provides a ratio where the value for the Junior "
		"professionals is the highest. "
		"Advised for projects where cost of production is of esence, "
		"and the number of professionals needed is below 5";
	info->levelDescp[3] =
		"Ideal for every project.The level provides a ratio wherein "
		"the values for Senior, Mid-level, and Junior professionals "
		"are equal or close to  being equal: BALANCED.";
}

/**
 * display_opt_info - displays details of optimization level
 * @optInfo: the optimization level to display information about.
 * @index: the index corresponding to the optimiztion level to be displayed.
 */
void display_opt_info(opt *optInfo, int *index)
{
	clearScreen();
	int choice, tracker;

	printf("==========================================================\n");
	printf("LEVEL: %s\n", optInfo->levelName[*index]);
	printf("----------------------------------------------------------\n");
	printf("INTRODUCTION:\n%s\n", optInfo->levelIntro[*index]);
	printf("----------------------------------------------------------\n");
	printf("DESCRIPTION:\n%s\n", optInfo->levelDescp[*index]);
	printf("==========================================================\n");
}

/**
 * init_levels - initialises proficiency levels.
 * @levels: pointer to the initialised devLevels type.
 */
void init_levels(devLevels *levels)
{
	levels->a = "SENIOR DEVELOPERS";
	levels->b = "MID-LEVEL DEVELOPERS";
	levels->c = "JUNIOR DEVELOPERS";
}

/**
 * print_levels -  printd to stdout professional levels.
 * @levels: a struct type holding levels descriptions.
 */
void print_levels(devLevels *levels)
{
	init_levels(levels);
	printf("WHAT LEVEL OF EXPERTISE DO YOU WANT MORE?\n");
	printf("==========================================================\n");
	printf("[1]. %s\n", levels->a);
	printf("[2]. %s\n", levels->b);
	printf("[3]. %s\n", levels->c);
	printf("==========================================================\n");
}
