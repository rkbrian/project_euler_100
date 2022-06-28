#include <iostream>
#include <string>
#include <atomic>

using namespace std;

/**
 * int_palindrome_checker - check whether a given number is a palindrome or not
 * @num: the given number
 * Return: 0 if it is a palindrome number, 1 if not
 */
int int_palindrome_checker(int num)
{
        int tmp = num, rev = 0;

        while (tmp > 0)
        {
                rev = rev * 10 + tmp % 10;
                tmp /= 10;
        }
        if (rev == num)
                return 0;
        return 1;
}

/**
 * str_palindrome_checker - find whether a given string is a palindrome or not
 * @str: the given string
 * Return: 0 if it is a palindrome, 1 if not
 */
int str_palindrome_checker(string str)
{
        int i = 0, j = str.length() - 1;

        while (i < j)
        {
                if (str[i] != str[j])
                        return 1;
                i++, j--;
        }
        return 0;
}

/**
 * bitwise_decToBin - convert a decimal number to binary, O(1) time
 * @num: the given number
 * Return: the binary number in string format
 */
string bitwise_decToBin(int dec)
{
        int bin = 0, i = 0;
        string bin_str = "";

        for (i = 31; i >= 0; i--)
        {
                bin = dec >> i;
                if (bin & 1)
                        bin_str += "1";
                else
                        bin_str += "0";
        }
        while (bin_str[0] == '0')
                bin_str.erase(0, 1);
        return bin_str;
}

/**
 * main - The decimal number, 585 = 1001001001 (binary), is palindromic in
 *  both bases.
 *  Find the sum of all numbers, less than one million, which are palindromic
 *  in base 10 and base 2.
 *  (Please note that the palindromic number, in either base, may not include
 *  leading zeros.)
 * Return: 0 for success, 1 for failure
 */
int main()
{
        int num = 1, sum = 0;

        while (num < 1000000)
        {
                if (int_palindrome_checker(num) == 0 && str_palindrome_checker(bitwise_decToBin(num)) == 0)
                        sum += num;
                num++;
        }
        cout << "final ans: " << sum << endl;
        return 0;
}
