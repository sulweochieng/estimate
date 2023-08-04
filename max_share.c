#include "main.h"
#include "types.h"
#include "fprtyps.h"
#include "globals.h"

/**
 * find_max_shares - finds ratios wherein a, b, or c are the highest.
 * @ratios: a dimensional array of possible ratios unto which we will be
 * finding the maximum of each ratio member.
 * @totalCombinations: the total number of the array's columns. We can as well
 * call it the total number of possible ratio combinations.
 * @aMaxIndex: the index at which [a] is maximum.
 * @bMaxIndex: the index at which [b] is maximum.
 * @cMaxIndex: the index at which [c] is maximum.
 */
void find_max_shares(int ratios[][SALARYLEVELS], int totalCombinations, int
		*aMaxIndex, int *bMaxIndex, int *cMaxIndex)
{
	int i;
	float aShare, bShare, cShare, aMaxShare = 0.0, bMaxShare = 0.0,
	      cMaxShare = 0.0;

	for (i = 0; i < totalCombinations; i++)
	{
		aShare = share_of_a(ratios[i][0], ratios[i][1], ratios[i][2]);
		bShare = share_of_b(ratios[i][0], ratios[i][1], ratios[i][2]);
		cShare = share_of_c(ratios[i][0], ratios[i][1], ratios[i][2]);

		if (aShare > aMaxShare)
		{
			aMaxShare = aShare;
			*aMaxIndex = i;
		}

		if (bShare > bMaxShare)
		{
			bMaxShare = bShare;
			*bMaxIndex = i;
		}

		if (cShare > cMaxShare)
		{
			cMaxShare = cShare;
			*cMaxIndex = i;
		}
	}
}
