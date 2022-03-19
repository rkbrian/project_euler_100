#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - n! means n × (n − 1) × ... × 3 × 2 × 1
 *  For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 *  and the sum of the digits in the number 10!
 *  is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *  Find the sum of the digits in the number 100!
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	/* max n = 100 increase digit counts by 2, max digit counts = 2 * 100 */
	size_t i = 100, f[200], j, x;

	memset(f, 0, 200 * sizeof(size_t)), f[0] = 1;
	for (; i > 0; i--)
	{
		x = 0;
		for (j = 0; j < 200; j++)
			f[j] *= i;
		for (j = 0; j < 200; j++)
		{
			f[j] += x;
			if (f[j] >= 10)
				x = f[j] / 10, f[j] = f[j] % 10;
			else
				x = 0;
		}
	}
	x = 0;
	for (j = 0; j < 200; j++)
		x += f[j];
	printf("Final ans: %lu\n", x);
	return (0);
}
