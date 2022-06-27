#include <iostream>
#include <atomic>

using namespace std;

int my_factorial(int n)
{
        if (n == 0)
                return 1;
        return n * my_factorial(n - 1);
}

/**
 * main - 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *  Find the sum of all numbers which are equal to the sum of the factorial
 *  of their digits.
 *  Note: As 1! = 1 and 2! = 2 are not sums they are not included.
 * Return: 0 for success, 1 for failure
 */ 
int main()
{
        // max factorial of one digit is 9! = 362880 (6 digits), max digit amount is 7,
        // because 9999999 > 362880 x 7 = 2540160, after this, putting more digit in 
        // front will always grow faster than summing the digit factorials.
        int num = 3, sum = 0, temp = 0, temp_sum = 0;

        while (num < 9999999)
        {
                temp = num, temp_sum = 0;
                while (temp > 0)
                {
                        temp_sum += my_factorial(temp % 10);
                        temp /= 10;
                }
                if (temp_sum == num)
                        cout << num << endl, sum += num;
                num++;
        }
        cout << "final ans: " << sum << endl;
        return 0;
}
