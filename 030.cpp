#include <iostream>
#include <atomic>

using namespace std;

int mypow(int a, int n) // higher efficientcy pow() function
{
        int r = 1;

        while (n > 0)
        {
                if (n & 1)
                        r *= a;
                a *= a; // repeatedly multiply the base by itself N times
                n >>= 1;
        } 
        return r;
}

/**
 * main - Surprisingly there are only three numbers that can be written
 *  as the sum of fourth powers of their digits:
 *     1634 = 1^4 + 6^4 + 3^4 + 4^4
 *     8208 = 8^4 + 2^4 + 0^4 + 8^4
 *     9474 = 9^4 + 4^4 + 7^4 + 4^4
 *  As 1 = 1^4 is not a sum it is not included.
 *  The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *  Find the sum of all the numbers that can be written as
 *  the sum of fifth powers of their digits.
 * Return: 0 if success, 1 if fail
 * Notes: these numbers are not necessarily Narcissistic Numbers
 *  because Narcissistic Number has a rule: digit count = exponent
 */
int main()
{
        int pow_n = 5, i, max_ten = 10, sum = 0, subsum, tmp;

        // upper limit: number l has x digits, possible max digit = 9, thus l <= x(9)^n.
        // obviously 9^n < 10^n, max x = 10 because starting from 10, adding another
        // digit of 9 will be no longer be able to keep the power-of-10-limit's digit down:
        // 10*(9)^n < 10^(n+1) ---- 9*10^n has n+1 digits, 10^(n+1) has n+2 digits
        for (i = 10; i < mypow(10, pow_n + 1); i++)
        {
                tmp = i, subsum = 0;
                while (tmp > 0)
                        subsum += mypow(tmp % 10, pow_n), tmp /= 10;
                if (subsum == i)
                        sum += subsum, cout << subsum << ", " << i << endl;
        }
        cout << "final ans: " << sum << endl;
        return 0;
}
