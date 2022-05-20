#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

/**
 * main - The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *  Find the sum of all the primes below two million.
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	unsigned long old_prime = 2, flag = 0, sum = 2;
	unsigned long target = 2, j, prime_lim = 2000000, caller = prime_lim / 20;

	if (prime_lim > 1)
		target++, old_prime++, sum += old_prime;
	while (target < prime_lim)
	{
		target += 2, flag = 0;
		if (target > (ULONG_MAX >> 1))
			break;
		for (j = 3; j <= (unsigned long)(sqrt(target)) + 1; j += 2)
		{
			if (target % j == 0 && target != j)
			{
				flag++;
				break;
			}
		}
		if (flag == 0 && target < prime_lim)
			sum += target, old_prime = target;
		if (target > caller)
			printf("-- Passed %lu\n", caller), caller += (prime_lim / 20);
	}
	printf("Final ans: sum = %lu\n", sum);
	printf("unsigned long  = %lu\n", ULONG_MAX);
	return (0);
}
