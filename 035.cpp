#include <iostream>
#include <math.h>
#include <atomic>

using namespace std;

/**
 * prime_checker - find whether a given number is a prime number or not
 * @num: the given number
 * Return: 0 if it is a prime number, 1 if not
 */
int prime_checker(int num)
{
        int factory = 3;

        if (num == 2)
                return 0;
        if (num % 2 == 0)
                return 1;
	while (factory < sqrt(num))
        {
                if (num % factory == 0)
                        return 1;
		factory += 2;
        }
        if (factory * factory == num)
                return 1;
	return 0;
}

/**
 * main - The number, 197, is called a circular prime because all rotations of
 *  the digits: 197, 971, and 719, are themselves prime.
 *  There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31,
 *  37, 71, 73, 79, and 97.
 *  How many circular primes are there below one million?
 * Return: 0 for success, 1 for failure
 */
int main()
{
        // 2 is counted as a prime number, so we start from 3.
        int num = 3, count = 1, tmp = 0, pow_ten = 1, digit = 0, circular_flag = 1;
        int limit = 1000000;

        while (num < limit)
        {
                if (prime_checker(num) == 0 && num > 10)
                {
                        tmp = num, pow_ten = 1;
                        while (tmp > 0)
                                pow_ten *= 10, tmp /= 10;
                        pow_ten /= 10, tmp = num, circular_flag = 1;
                        digit = tmp % 10, tmp = (digit * pow_ten) + (tmp / 10);
                        while (tmp != num)
                        {
                                if (prime_checker(tmp) == 1)
                                {
                                        circular_flag = 0;
                                        break;
                                }
                                digit = tmp % 10, tmp = (digit * pow_ten) + (tmp / 10);
                        }
                        if (circular_flag == 1)
                                count++, cout << num << endl;
                }
                else if (prime_checker(num) == 0)
                        count++, cout << num << endl;
                num += 2;
        }
        cout << "final ans: " << count << endl;
        return 0;
}
