#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * main - By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
 *  we can see that the 6th prime is 13. What is the 10001st prime number?
 *  Note: O(n^2) with modulo, taking a long time (2+ seconds)
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	unsigned long old_prime = 2, flag = 0;
	unsigned long target = 2, i = 1, j, end_i = 10001;

	if (end_i > 1)
		target++, old_prime++, i++;
	while (i < end_i)
	{
		target += 2, flag = 0;
		if (target > (ULONG_MAX >> 1))
			break;
		for (j = 3; j <= old_prime; j += 2)
		{
			if (target % j == 0)
			{
				flag++;
				break;
			}
		}
		if (flag == 0)
			i++, old_prime = target;
	}
	printf("Final ans: %lu\n", target);
	return (0);
}
