#include <iostream>
#include <math.h>
#include <atomic>

using namespace std;

int prime_sum = 0;
int prime_count = 0;

/**
 * prime_checker - find whether a given number is a prime number or not
 * @num: the given number
 * Return: 0 if it is a prime number, 1 if not
 */
int prime_checker(int num)
{
        int factory = 3;

        if (num <= 1)
                return 1;
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
 * prime_append - recursively append a digit to the end of the prime number
 *  to create a new prime number
 * @a: the number to append
 */
void prime_append(int a)
{
        int digit_bank[5] = {1, 3, 7, 9};
        int i = 0, tmp = a, pow_ten = 1, digit = 0, flag = 0;

        while (tmp > 0)
                pow_ten *= 10, tmp /= 10;
        pow_ten /= 10, tmp = a;
        // check if the number is a truncatable prime number from left to right
        while (a > 10 && tmp > 0)
        {
                digit = tmp / pow_ten;
                tmp = tmp - pow_ten * digit, pow_ten /= 10;
                if (tmp == 0)
                        break;
                if (prime_checker(tmp) == 1)
                {
                        flag = 1;
                        break;
                }
        }
        // store the trucatable prime number
        if (flag == 0 && a > 10)
        {
                cout << "new found truncatable prime: " << a << endl;
                prime_sum += a, prime_count++;
        }
        // append prime number on right, new prime number is truncatable from right to left
        for (i = 0; i < 4; i++)
        {
                if (prime_checker(a * 10 + digit_bank[i]) == 0)
                        prime_append(a * 10 + digit_bank[i]);
        }
}

/**
 * main - The number 3797 has an interesting property. Being prime itself,
 *  it is possible to continuously remove digits from left to right, and
 *  remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work
 *  from right to left: 3797, 379, 37, and 3.
 *  Find the sum of the only eleven primes that are both truncatable from
 *  left to right and right to left.
 *  NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 * Return: 0 for success, 1 for failure
 */
int main()
{
        int prime_bank[5] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++)
                prime_append(prime_bank[i]);
        cout << "final ans: " << prime_sum << endl;
        cout << "final count: " << prime_count << endl;
}
