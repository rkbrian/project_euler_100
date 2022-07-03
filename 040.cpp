#include <iostream>
#include <string>
#include <atomic>

using namespace std;

/**
 * digitChampion - find the nth digit of concatenation of all numbers from 1 to n.
 * @n: the number.
 * Return: the nth digit of concatenation of all numbers from 1 to n.
 */
int digitChampion(int n)
{
        int i = 1, subtotal = 0, j;
        string str_n = to_string(0);

        if (n <= 0)
                return 0;
        str_n = to_string(i);
        while (subtotal + str_n.length() < n)
        {
                subtotal += str_n.length();
                i++, str_n = to_string(i);
        }
        if (subtotal + str_n.length() == n)
                return i % 10;
        for (j = 0; j < str_n.length(); j++)
        {
                if (j + 1 + subtotal == n)
                        break;
        }
        return str_n[j] - '0';
}

/**
 * main - Champernowne's constant:
 *  An irrational decimal fraction is created by concatenating
 *  the positive integers:
 *  0.123456789101112131415161718192021...
 *  It can be seen that the 12th digit of the fractional part is 1.
 *  If dn represents the nth digit of the fractional part,
 *  find the value of the following expression.
 *  d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 * Return: 0 if success, 1 otherwise
 */
int main()
{
        int limit = 1000000, i, product = 1;

        for (i = 1; i <= limit; i *= 10)
                cout << "d" << i << " = " << digitChampion(i) << endl, product *= digitChampion(i);
        cout << "final ans: " << product << endl;
        return 0;
}
