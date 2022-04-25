#include <iostream>
#include <vector>
#include <atomic>

using namespace std;

/**
 * main - find whether a given number is a prime number or not
 * @num: the given number
 * Return: 0 if it is a prime number, 1 if not
 */
int prime_checker(int num)
{
        int factory = 2;

	while (num % factory > 0)
		factory++;
	if (num == factory)
                return 0;
	return 1;
}

/**
 * main - Considering quadratics of the form:
 *  n^2 + a * n + b, where |a| < 1000 and |b| <= 1000
 *  where |n| is the modulus/absolute value of n
 *  Find the product of the coefficients, a and b, for the quadratic
 *  expression that produces the maximum number of primes for consecutive
 *  values of n, starting with n = 0.
 * Return: 0 if success, 1 if fail
 *  Notes: O(n^4), already optimized with:
 *   - b range [2, 1000];
 *   - |a| range [0, sqrt(4 * b));
 *   - checking >0 and <0 values of |a| in the same loop,;
 *   - checking a=0 case only once;
 */
int main()
{
        int consec_record = 0, ab = 0, a, b, n;

        // results always > 0, delta = B^2 - 4AC must be < 0, in this case a^2 < 4*b,
        // when n = 0, result = b, so b >= 2 for the headstart prime.
        b = 1000;
        while (b >= 2)
        {
                a = 0;
                while (a * a <= 4 * b)
                        a++;
                a--;
                while (a >= 0) // check |a|
                {
                        n = 0;
                        while (n >= 0)
                        {
                                if (prime_checker((n * n) + (a * n) + b))
                                        break;
                                n++;
                        }
                        if (n > consec_record) // n also represents the amount of the consecutive primes
                                consec_record = n, ab = a * b, cout << "  consecutive prime count with possitive a: " << n << endl;
                        if (a)
                        {
                                a *= -1, n = 0;
                                while (n >= 0)
                                {
                                        if (prime_checker((n * n) + (a * n) + b))
                                                break;
                                        n++;
                                }
                                if (n > consec_record)
                                        consec_record = n, ab = a * b, cout << "  consecutive prime count with negative a: " << n << endl;
                                a *= -1;
                        }
                        a--;
                }
                if (b % 50 == 0 || (b < 100 && (b % 10 == 0)))
                        cout << "checked b value of " << b << endl;
                b--;
        }
	cout << "final ans: " << ab << endl;
        return 0;
}
