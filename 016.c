#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * main - 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *  What is the sum of the digits of the number 2^1000?
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	long memo[1024]; /*stores decimal digits in reversed order*/
	long power_lim = 1000, i = 0, j = 1, k, digi_sum = 0, buff;

	memset(memo, 0, 1024 * sizeof(memo[0])), memo[0] = 1;
	while (i < power_lim)
	{
		i++, buff = 0;
		for (k = 0; k < j; k++)
		{
			memo[k] <<= 1, memo[k] += buff;
			if (memo[k] >= 10)
				buff = memo[k] / 10, memo[k] = memo[k] % 10;
			else
				buff = 0;
			if (memo[j - 1] >= 5)
				j++;
		}
	}
	i = 0;
	while (i < j)
		digi_sum += memo[i], i++;
	printf("Final ans: %ld\n", digi_sum), memset(memo, 0, 1024 * sizeof(memo[0]));
	return (0);
}
