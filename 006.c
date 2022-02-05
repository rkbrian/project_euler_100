#include <stdio.h>
#include <stdlib.h>

/**
 * main - The sum of the squares of the first ten natural numbers is,
 *  1^2 + 2^2 + 3^2 + ... + 10^2 = 385
 *  The square of the sum of the first ten natural numbers is,
 *  (1 + 2 + 3 + ... + 10)^2 = 55^2 = 3025
 *  Hence the difference between the sum of the squares of the first ten
 *  natural numbers and the square of the sum is.
 *  3025 - 285 = 2640
 *  Find the difference between the sum of the squares of the first one
 *  hundred natural numbers and the square of the sum.
 *  Note: sum of squares of natural num:
 *  1^2 + 2^2 + 3^2 + ... + n^2 = n * (n + 1) * (2n + 1) / 6
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	long num = 100, sum_sq, big_sq;

	big_sq = (1 + num) * num / 2, big_sq *= big_sq;
	sum_sq = num * (num + 1) * (2 * num + 1) / 6;
	printf("Final ans: %ld\n", big_sq - sum_sq);
	return (0);
}
