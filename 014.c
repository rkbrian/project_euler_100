#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * main - The following iterative sequence is defined for the set of positive integers:
 *  n → n/2 (n is even)
 *  n → 3n + 1 (n is odd)
 *  Using the rule above and starting with 13, we generate the following sequence:
 *  13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *  It can be seen that this sequence (starting at 13 and finishing at 1)
 *  contains 10 terms. Although it has not been proved yet (Collatz Problem),
 *  it is thought that all starting numbers finish at 1.
 *  Which starting number, under one million, produces the longest chain?
 *  Note: Once the chain starts the terms are allowed to go above one million.
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	long lim = 1000000, x = lim, rec = 0, max_val = 0, max_rec = 0;

	while (x > 1)
	{
		rec = 0;
		while (x > 1)
		{
			if (x % 2)
				x = x * 3 + 1, rec++;
			else
				x >>= 1, rec++;
			if (rec > max_rec)
				max_val = lim, max_rec = rec;
		}
		lim--, x = lim;
	}
	printf("Final ans: max num %ld, count of operations %ld\n", max_val, max_rec);
	return (0);
}
