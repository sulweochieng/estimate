#include "../headers/main.h"
#include "../headers/types.h"
#include "../headers/fprtyps.h"
#include <time.h>
/**
 * generate_ratio_list - generates all possible ratios for computing the
 * estimate costs.
 * @n: the number of specific specialists needed for the project.
 * @ratiosList: struct type to hold the various ratio values [a]:[b]:[c].
 * @count:tracker of all possible ratios got from sharing [n] items among three
 * people.
 */
void generate_ratio_list(int n, ratio *ratiosList, unsigned long int *count)
{
	int a, b, c;
	*count = 0;
	for (a = 1; a <= n - 2; a++)
	{
		for (b = 1; b <= n - a - 1; b++)
		{
			c = (n - a) - b;

			ratiosList[*count].a = a;
			ratiosList[*count].b = b;
			ratiosList[*count].c = c;
			(*count)++;
		}
	}
	printf("%lu POSIBLE RATIOS\n", *count);
}

/**
 * clearScreen - Check the platform and use the appropriate clear command.
 */
void clearScreen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

/**
 * salut - welcomes the user depending on their local time.
 */
void salut(void)
{
	time_t rawtime;
	struct tm *timeinfo;
	char *username = NULL;
	const char *greeting;
	int hour;

	username = getenv("USER");
	if (!username)
		username = getenv("USERNAME");

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	hour = timeinfo->tm_hour;

	if (hour < 12)
		greeting = "Good morning";
	else if (hour < 18)
		greeting = "Good afternoon";
	else
		greeting = "Good evening";

	printf("\n%s, %s!\n", greeting, username);
}
