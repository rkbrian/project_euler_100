#include <iostream>
#include <algorithm> // next_permutation(1st item, last item), handy func
#include <atomic>

using namespace std;

/**
 * main - A permutation is an ordered arrangement of objects. For example,
 *  3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of
 *  the permutations are listed numerically or alphabetically, we call it
 *  lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *  012   021   102   120   201   210
 *  What is the millionth lexicographic permutation of the digits
 *  0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 * Return: 0 if success, 1 if fail
 */
int main()
{
	string thisstr = "0123456789";
	size_t high_lim = 1000000, i = 1;

	while (next_permutation(thisstr.begin(), thisstr.end()))
	{
                i++;
		if (i == high_lim)
			break;
	}
        cout << "final ans: " << thisstr << endl;
	return 0;
}
