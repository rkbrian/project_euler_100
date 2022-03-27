#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
 * main - A perfect number is a number for which the sum of its proper divisors
 *  is exactly equal to the number. For example, the sum of the proper divisors
 *  of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *  A number n is called deficient if the sum of its proper divisors is less
 *  than n and it is called abundant if this sum exceeds n.
 *  As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 *  number that can be written as the sum of two abundant numbers is 24.
 *  By mathematical analysis, it can be shown that all integers greater than
 *  28123 can be written as the sum of two abundant numbers. However, this
 *  upper limit cannot be reduced any further by analysis even though it is
 *  known that the greatest number that cannot be expressed as the sum of
 *  two abundant numbers is less than this limit.
 *  Find the sum of all the positive integers which cannot be written
 *  as the sum of two abundant numbers.
 * Return: 0 if success, 1 if fail
 */
int main()
{
	size_t reg_sum, real_sum = 0, low_lim = 24, high_lim = 28123, tmp;
        size_t leap = 12; // the smallest abundant number as leap of iteration

        reg_sum = (low_lim + high_lim) * (high_lim - low_lim + 1) / 2;
        reg_sum -= (low_lim + (size_t)(high_lim / leap) * leap) * (1 + (high_lim - low_lim) / leap) / 2;
        cout << reg_sum << " and " << real_sum << endl;
        return 0;
}
