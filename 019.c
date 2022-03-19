#include <stdio.h>
#include <stdlib.h>

/**
 * main - 1 Jan 1900 was a Monday.
 *  A leap year occurs on any year evenly divisible by 4,
 *  but not on a century unless it is divisible by 400.
 *  How many Sundays fell on the first of the month during
 *  the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	/*1900 is not a leap year, after that every 4 yr is*/
	/*starting point: 365 % 7 = 1, 365 / 7 = 52, yr 1900 has 53 Mondays*/
	/*6th day of 1901 is Sunday*/
	size_t yrs = 2000 - 1901 + 1;
	size_t i, j, first_suns = 0, start = 5;
	size_t arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (i = 1; i <= yrs; i++)
	{
		arr[1] = 28;
		if (i % 4 == 0 && i % 100 > 0)
			arr[1] = 29;
		else if (i % 400 == 0)
			arr[1] = 29;
		for (j = 0; j < 12; j++)
		{
			if (start == 0)
				first_suns++;
			start = ((arr[j] % 7) + start) % 7;
		}
	}
	first_suns++; /*adding start point Sunday*/
	printf("Final ans: %lu\n", first_suns);
	return (0);
}
