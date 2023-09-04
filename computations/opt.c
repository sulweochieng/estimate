#include "../headers/main.h"
#include "../headers/types.h"

/**
 * initOptimizationInfo - initiates the optimization infomation.
 * @info: pointer to type opt that holds the optimization information.
 */
void init_optimization_info(opt *info)
{
	info->levelName[0] = "OPTIMUM";
	info->levelName[1] = "SUB-OPTIMAL";
	info->levelName[2] = "BASIC";
	info->levelName[3] = "EQUILLIBRIUM";

	info->levelIntro[0] = "Highest level of optimization";
	info->levelIntro[1] = "Inter-mediate level of optimization";
	info->levelIntro[2] = "Basic level of optimization";
	info->levelIntro[3] = "Balanced level of optimization";

	info->levelDescp[0] = "The level provides a ratio wherein the value for the Senior Dev is the highest. Advised for Projects HIGHEST level of professionalism is required. It will involve the highest cost.";
	info->levelDescp[1] = "The level provides a ratio where the the value for the Mid-Level Dev is the highest. Advised for projects where time is of essence.";
	info->levelDescp[2] = "The level provides a ratio where the value for the Junior Dev is the highest. Advised for projects where cost of production is of esence.";
	info->levelDescp[3] = "The level provides a ratio wherein the values for Senior, Mid-level, and Junior Devs are equal or close to equal.";
}

/**
 * initLevels - initialises proficiency levels.
 * @levels: pointer to the initialised devLevels type.
 */
void init_levels(devLevels *levels)
{
	levels->a = "SENIOR DEVELOPERS";
	levels->b = "MID-LEVEL DEVELOPERS";
	levels->c = "JUNIOR DEVELOPERS";
}
