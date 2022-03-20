#include <iostream>
#include <atomic>

using namespace std;

/**
 * the_d_function - function to sum up all divisors of a integer x
 *  (divisible to these divisors), all divisors are less than x.
 * @x: integer
 * Return: the sum of all divisors
 */
size_t the_d_function(size_t x)
{
	size_t y = 0, i = 1, mid_point = x;

	while (i < mid_point)
	{
		if (x % i == 0)
		{
			y += i, mid_point = x / i;
			if (mid_point != x)
				y += mid_point;
		}
		i++;
		if (i >= mid_point)
			break;
	}
	return y;
}

/**
 * main - Let d(n) be defined as the sum of proper divisors of n
 *  (numbers less than n which divide evenly into n).
 *  If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair
 *  and each of a and b are called amicable numbers.
 *  For example, the proper divisors of 220 are
 *  1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
 *  The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *  Evaluate the sum of all the amicable numbers under 10000.
 * Return: 0 if success, 1 if fail
 */
int main()
{
	size_t a, b, limity = 10000, amicable_sum = 0;

	for (a = 1; a < limity; a++)
	{
		b = the_d_function(a);
		if (the_d_function(b) == a && (a < b || a > b))
			cout << "a & b: " << a << " and " << b << endl, amicable_sum += a;
	}
	cout << "final ans: " << amicable_sum << endl;
	return 0;
}
