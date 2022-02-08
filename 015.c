#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * main - Starting in the top left corner of a 2×2 grid, and only being able
 *  to move to the right and down, there are exactly 6 routes to the bottom
 *  right corner.
 *  How many such routes are there through a 20×20 grid?
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	unsigned long g_size = 20, n, k, num = 1;

	/*always the same amount of steps, total 40, only "right" and "down" going*/
	/*both amounts are fixed, route doesn't consider order: n! / (k! (n - k)!)*/
	/*result too big, remove unnecessary calc*/
	n = g_size * 2, k = n - g_size;
	while (n > 0)
	{
		if (n > g_size) /*simulating: n! / (n - k)!*/
			num *= n;
		n--;
		while (k && num % k == 0) /*simulating: result / k!*/
			num /= k, k--;
	}
	printf("ULONG MAX: %lu\nFinal ans: %lu\n", ULONG_MAX, num);
	return (0);
}
