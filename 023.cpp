#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <atomic>

using namespace std;

class Node {
	public:
		size_t abundant;
		Node *next; // pointer to next node
};

Node *createnode(size_t val)
{
	Node *nodey;
	size_t i;

	nodey = new Node();
	if (!nodey)
		return NULL;
	nodey->abundant = val, nodey->next = NULL;
	return nodey;
}

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
			if (mid_point != x && mid_point != i)
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
 * Notes: slow, 2min 50s
 * Return: 0 if success, 1 if fail
 */
int main()
{
	long reg_sum, ab_sum = 0, low_lim = 24, high_lim = 28123, a, b, i = 0;
	Node *tmp, *curr = NULL, *head = NULL;

	reg_sum = (1 + high_lim) * (high_lim) / 2;
	cout << "Regular sum from 24 to 28123 is: " << reg_sum << endl;
	for (a = 12; a <= high_lim; a++) // list of abundant numbers
	{
		b = the_d_function(a);
		if (b > a)
			tmp = createnode(a), i++;
		if (b > a && !head)
			head = tmp, curr = head;
		else if (b > a)
			curr->next = tmp, curr = curr->next;
	}
	curr->next = NULL, curr = head, cout << "abundant number count: " << i << endl;
	for (a = low_lim; a <= high_lim; a++) // sum of all numbers that can be written as sum of 2 ab nums
	{
		curr = head;
		while (curr && curr->abundant < a)
		{
			i = a - curr->abundant, b = the_d_function(i);
			if (b > i)
			{
				ab_sum += a;
				break;
			}
			curr = curr->next;
		}
		b = 0, i = 0;
		if (a % 500 == 0)
			cout << a << endl;
	}
	i = reg_sum - ab_sum, cout << "final ans: " << i << endl, curr = head;
	while (curr)
		tmp = curr, curr = curr->next, free(tmp);
	return 0;
}
