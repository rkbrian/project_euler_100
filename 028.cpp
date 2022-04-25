#include <iostream>
#include <atomic>

using namespace std;

/**
 * main - Starting with the number 1 and moving to the right in a clockwise
 *  direction a 5 by 5 spiral is formed as follows:
 *      21 22 23 24 25
 *      20  7  8  9 10
 *      19  6  1  2 11
 *      18  5  4  3 12
 *      17 16 15 14 13
 *  It can be verified that the sum of the numbers on the diagonals is 101.
 *  What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 *  formed in the same way?
 * Return: 0 if success, 1 if fail
 */
int main()
{
        int sum = 1, side = 3, end_side = 1001;

        // each rotate ends at the square number, vertex in arithmetic sequence
        // from 1st vertex to the last / sq num, each rotate's sum = (sq_num + 1st_v) * 2
        // = (sq_num + sq_num - (side - 1) * 3) * 2
        while (side <= end_side)
        {
                sum += 2 * (side * side * 2 - (side - 1) * 3);
                side += 2;
        }
        cout << "final ans: " << sum << endl;
        return 0;
}
