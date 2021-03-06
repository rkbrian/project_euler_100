#include <stdio.h>
#include <stdlib.h>

static long rec_fib(long num)
{
	if (num <= 1)
		return (1);
	return (rec_fib(num - 1) + rec_fib(num - 2));
}

/**
 * main - Each new term in the Fibonacci sequence is generated by adding the
 *  previous two terms. By starting with 1 and 2, the first 10 terms will be:
 *  1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *  (1st, 2nd, 3rd, ... value)
 *  By considering the terms in the Fibonacci sequence whose values do not
 *  exceed four million, find the sum of the even-valued terms.
 *  Note: I wish there's a solution with less time complexity
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	long nth = 4000000, sum = 0;

	for (long i = 2; rec_fib(i) <= nth; i += 3) /*even num after every 3 values*/
		sum += rec_fib(i);
	printf("Final ans: %ld\n", sum);
	return (0);
}
