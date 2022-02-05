#include <stdio.h>
#include <stdlib.h>

/**
 * common_div - function to find the greatest common divisor of 2 given int 
 * @target: 1st integer
 * @factory: 2nd integer
 * Return: the greatest common divisor
 */
static long common_div(long target, long factory)
{
	long mult_memo = 0, i = 1;

	while (i <= target && i <= factory)
	{
		if (target % i == 0 && factory % i == 0)
			mult_memo = i;
		i++;
	}
	return (mult_memo);
}

/**
 * main - 2520 is the smallest number that can be divided by each of the
 *  numbers from 1 to 10 without any remainder.
 *  What is the smallest positive number that is evenly divisible by all of
 *  the numbers from 1 to 20?
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	long num = 20, factory = 1, target = 1;

	while (factory <= num)
	{
		target = target * factory / common_div(target, factory);
		factory++;
	}
	printf("Final ans: %ld\n", target);
	return (0);
}
