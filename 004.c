#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - old function of mine. Checks if an unsigned long integer
 *  is a palindrome.
 *  Notes: my method uses a big divisor (in power of 10) to find & behead
 *  the 1st digit, uses modulo to find the last digit, time complexity O(n).
 * @n: unsigned long integer to be checked
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome 
 */
static int is_palindrome(long n)
{
	long pow_of_ten = 1, pow = 0;

	if (n < 10)
		return (1);
	while (pow_of_ten <= n && pow < 20)
	{
		pow++;
		if (pow < 20)
			pow_of_ten *= 10;
	}
	if (pow < 20)
		pow_of_ten /= 10;
	pow /= 2; /*the middle index & the max divisor*/
	while (pow > 0)
	{
		if (n / pow_of_ten != n % 10)
			return (0);
		n = n % pow_of_ten;
		n /= 10;
		pow--, pow_of_ten /= 100;
	}
	return (1);
}

static long max_val(long num)
{
	static long ret;

	if (num > ret)
		ret = num;
	return (ret);
}

/**
 * main - A palindromic number reads the same both ways. The largest
 *  palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *  Find the largest palindrome made from the product of two 3-digit numbers.
 *  Note: big time complexity, I don't like it.
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	long a = 999, b = 999, c;

	/*c has even number of digits, such palindrome int is always a multiple of 11*/
	/*consider one of a and b is a multiple of 11, the biggest it can get is 990, now control the other end*/
	c = a * b;
	while (is_palindrome(c) == 0)
		c--;
	a = 990, b = c / a;
	if (b > 999)
		b = 999;
	c = b;
	while (a > 2)
	{
		while (b > 2)
		{
			if (is_palindrome(a * b) == 1)
				max_val(a * b);
			b--;
		}
		b = c, a -= 11;
	}
	printf("Final ans: %ld\n", max_val(0));
	return (0);
}
