#include <stdio.h>
#include <stdlib.h>

/**
 * main - If we list all the natural numbers below 10 that are multiples of
 *  3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *  Find the sum of all the multiples of 3 or 5 below 1000.
 * Note: no loop, O(1)
 * @argc: argument count
 * @argv: argument stream
 * Return: 0 if success, 1 if fail
 */
int main(int argc, char *argv[])
{
	long max_num, a = 3, b = 5, a_count, b_count, ab_count, res_a, res_b;

	if (argc != 2)
	{
		printf("Error: please provide a valid number\n");
		return (1);
	}
	max_num = atoi(argv[1]);
	if (max_num % a > 0)
		a_count = max_num / a;
	else
		a_count = (max_num - 1) / a;
	if (max_num % b > 0)
		b_count = max_num / b;
	else
		b_count = (max_num - 1) / b;
	if (max_num % (a * b) > 0)
		ab_count = max_num / a / b;
	else
		ab_count = (max_num - 1) / a / b;
	/*sum of multiples of a*/
	res_a = (a + a_count * a) * a_count / 2;
	/*sum of multiples of b - sum of multiples of ab*/
	res_b = ((b + b_count * b) * b_count / 2) - (((a * b) + ab_count * (a * b)) * ab_count / 2);
	printf("Final ans: %ld\n", res_a + res_b);
	return (0);
}
