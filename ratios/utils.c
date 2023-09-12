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
void clearScreen(void)
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

	printf("\n%s %s!\n", greeting, username);
}

/**
 * choice_check - checks if the user inputs a required index within required
 * bounds.
 * @range: the upper and lower limits required for input, incases where choices
 * are to be made.
 * Desription: if the input does not not require a range, let's say when a user
 * is inputting cost/salary, the range is set to 0.
 * @input: the varibale to store the user input.
 */		
void choice_check(int *input, int range) 
{
	char inputStr[20];
	bool validInput = false;

	while (!validInput)
	{
        	printf("Enter a valid index: ");
        	if (scanf("%19s", inputStr) != 1)
		{
			printf("Invalid input. Please enter a valid index.\n");
            		clear_input_buffer();
		}
		else
		{
			validInput = true;
			for (int i = 0; inputStr[i] != '\0'; i++)
			{
                		if (i == 0 && inputStr[i] == '-')
				{
					continue;
				}
				if (!isdigit(inputStr[i]))
				{
					validInput = false;
					break;
				}
			}
			if (validInput)
			{
				*input = atoi(inputStr);
				if (*input < 1 || *input > range)
				{
					printf("Input out of range. Please enter a valid index.\n");
					validInput = false;
				}
			}
			if (!validInput)
			{
				printf("Invalid input. Please enter a valid index.\n");
				sleep(1);
				clear_input_buffer();
			}
		}
	}
}

/**
 * lf_check - checks if the user has inputed an actual double.
 * @input: input container.
 */
void lf_check(double *input)
{
	if (scanf("%lf", input) == 0)
	{
		printf("PLEASE INPUT A VALID AMOUNT\n");
		sleep(1);
		return;
	}
}
