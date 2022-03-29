#include <iostream>
#include <atomic>

using namespace std;

/**
 * main - The Fibonacci sequence is defined by the recurrence relation:
 *  Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
 *  Hence the first 12 terms will be:
 *  F1 = 1
 *  F2 = 1
 *  F3 = 2
 *  F4 = 3
 *  F5 = 5
 *  F6 = 8
 *  F7 = 13
 *  F8 = 21
 *  F9 = 34
 *  F10 = 55
 *  F11 = 89
 *  F12 = 144
 *  The 12th term, F12, is the first term to contain three digits.
 *  What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 * Return: 0 if success, 1 if fail
 */
int main()
{
	// Time complexity O(n). My method only calculates first 5 digits of a
	// Fibonacci number, any Fn less than 10^5 is out of consideration in the
	// digit counting since the goal is 1000 digits.
	// 5 digits rounding is enough to find the 1st digit.
	size_t arr[3] = {2, 3, 5}; // Fn with 1st 5 valid digits, index n, total digits
	size_t high_lim = 1000, a = 1, b = 5, tmp;

	while (arr[2] < high_lim)
	{
		tmp = arr[0], arr[0] += a, b = arr[2], arr[1]++;
		if (arr[0] > 99999)
			arr[0] /= 10, arr[2]++;
		if (arr[2] == high_lim)
			break;
		else if (arr[2] > b)
			b++, tmp /= 10;
		a = tmp;
	}
	cout << "final ans: " << arr[1] << endl;
	return 0;
}
