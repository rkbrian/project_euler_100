#include <stdio.h>
#include <stdlib.h>

/**
 * main - A Pythagorean triplet is a set of three natural numbers, a < b < c,
 *  for which, a^2 + b^2 = c^2
 *  There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *  Find the product abc.
 *  Note: main function shows how I found the three numbers,
 *  then the abc product.
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	int a, b, c, sum = 1000, sum_half, flag = 0, tmp;

	/*a + b = sum - c, (a + b)^2 = a^2 + b^2 + 2ab*/
	/*a^2 + b^2 = (sum - c)^2 - 2ab = c^2, sum^2 -2sum*c - 2ab = 0*/
	/*sun^2 and sum * c are in multple of 1000, so does a * b*/
	sum_half = sum / 2; /*500*/
	a = 1;
	while (a * a < 1000) /*for a * b being multiple of 1000*/
		a++;
	b = a + 1, c = sum - a - b;
	while (a < 1000 / 3 && a*a + b*b != c*c)
	{
		a++, b = a + 1, flag = 0;
		while (a * b % 1000)
		{
			b++;
			if (a + 2 * b > 1000)
			{
				flag = 1;
				break;
			}
		}
		tmp = a * b;
		if (!flag)
		{
			c = 1000 - a - b;
			while (sum_half != c + a * b / 1000)
			{
				tmp += 1000, b = (tmp) / a, c = 1000 - a - b;
				if (a + 2 * b > 1000)
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
				printf("Temp: a = %d, b = %d, c = %d\n", a, b, c);
		}
		c = 1000 - a - b;
	}
	printf("Final ans: a = %d, b = %d, c = %d, abc = %d\n", a, b, c, a * b * c);
	return (0);
}
