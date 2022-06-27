#include <iostream>
#include <atomic>

using namespace std;

/**
 * lowest_deno - function to define the lowest integer form of the denominator
 *  in a fraction, given the numerator and the denominator
 * @a: the numerator
 * @b: the denominator
 * Return: the lowest integer form of the denominator
 */
int lowest_deno(int a, int b)
{
        int factor = 2;

        while (factor <= a && factor <= b)
        {
                while (a % factor == 0 && b % factor == 0)
                        a /= factor, b /= factor;
                factor++;
        }
        return b;
}

/**
 * main - The fraction 49/98 is a curious fraction, as an inexperienced
 *  mathematician in attempting to simplify it may incorrectly believe that
 *  49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 *  We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *  There are exactly four non-trivial examples of this type of fraction,
 *  less than one in value, and containing two digits in the numerator and
 *  denominator.If the product of these four fractions is given in its lowest
 *  common terms, find the value of the denominator.
 * Return: 0 for success, 1 for failure
 */
int main()
{
        int a, b, digit, pro_a = 1, pro_b = 1;

        // digit amount to be cancelled out: 1
        // digit amount on numerator and denominator: 1
        // I assume the question only considers this case:
        // ax/xb = a/b, and a,b,x are 1 digit numbers
        a = 1, b = 2, digit = 1;
        while (digit < 10)
        {
                while (a < 10)
                {
                        while (b < 10)
                        {
                                if (((a * 10) + digit) * b == a * (b + (digit * 10)) && a != b)
                                {
                                        cout << a << "/" << b << ", " << a << digit << "/" << digit << b << endl;
                                        pro_a *= a, pro_b *= b;
                                }
                                b++;
                        }
                        a++, b = a + 1;
                }
                a = 1, b = 2, digit++;
        }
        cout << "final ans: " << lowest_deno(pro_a, pro_b) << endl;
        return 0;
}
