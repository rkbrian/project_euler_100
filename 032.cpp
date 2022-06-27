#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <atomic>

using namespace std;

/**
 * unique_int - function to define if all digits are unique in a number
 * @num: number to be checked
 * Return: 0 if all digits are unique, 1 otherwise
 */
int unique_int(int num)
{
        vector<int> hashTable = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int i = 0, digit = 0;

        while (num)
                digit = num % 10, hashTable[digit]++, num = num / 10;
        for (i = 0; i < 10; i++)
        {
                if (hashTable[i] > 1) // each digit must be unique or not exist in the number
                        return 1;
        }
        return 0;
}

/**
 * pandigital_test - function to find if all digits from the given numbers
 *  are pandigital from 1 to 9
 * @a: the 1st number to be checked
 * @b: the 2nd number to be checked
 * @ab: the 3rd number to be checked
 * Return: 0 if all digits are pandigital, 1 otherwise
 */
int pandigital_test(int a, int b, int ab)
{
        vector<int> hashTable = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int i = 0, digit = 0;

        while (a)
                digit = a % 10, hashTable[digit]++, a = a / 10;
        while (b)
                digit = b % 10, hashTable[digit]++, b = b / 10;
        while (ab)
                digit = ab % 10, hashTable[digit]++, ab = ab / 10;
        for (i = 0; i < 10; i++)
        {
                if (hashTable[i] != 1) // each digit must be unique and exist in the number
                        return 1;
        }
        return 0;
}

/**
 * main - We shall say that an n-digit number is pandigital if it makes use
 *  of all the digits 1 to n exactly once;
 *  for example, the 5-digit number, 15234, is 1 through 5 pandigital.
 *  The product 7254 is unusual, as the identity, 39 × 186 = 7254,
 *  containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 *  Find the sum of all products whose multiplicand/multiplier/product identity
 *  can be written as a 1 through 9 pandigital.
 *  Hint: Some products can be obtained in more than one way so be sure to only
 *  include it once in your sum.
 * Return: 0 if success, 1 if fail
 * Note: nested loops of 3, but I managed to reduce the ranges of the
 *  multiplicand and the multiplier, the 3rd loop max length is 9.
 */
int main()
{
        int a = 2, b, amax, bmax, ab = 0, sum = 0;
        set<int> products; // set records unique values only

        // a cannot be 1 because it makes b = ab, so starting from 2
        // let a be the smaller factor, b be the bigger one
        // min a = 2, max b share equal amount of digits with max ab, max b length = 4
        bmax = 9876 / 2;
        while (unique_int(bmax))
                bmax--;
        amax = sqrt(bmax);
        while (a < amax)
        {
                while (unique_int(a))
                        a++;
                b = bmax;
                while (b > amax)
                {
                        ab = a * b;
                        if (pandigital_test(a, b, ab) == 0)
                        {
                                cout << "a: " << a << "; b: " << b << "; ab: " << ab << endl;
                                products.insert(ab);
                        }
                        b--;
                }
                a++;
        }
        for (auto i = products.begin(); i != products.end(); i++)
                cout << *i << " ", sum += *i;
        cout << endl << "final ans: " << sum << endl;
        return 0;
}
