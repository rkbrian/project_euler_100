#include <iostream>
#include <vector>
#include <math.h>
#include <atomic>

using namespace std;

/**
 * main - If p is the perimeter of a right angle triangle with integral
 *  length sides, {a,b,c}, there are exactly three solutions for p = 120.
 *  {20,48,52}, {24,45,51}, {30,40,50}
 *  For which value of p ≤ 1000, is the number of solutions maximised?
 * Return: 0 if success, 1 otherwise
 */
int main()
{
        // a is the shorter leg, b is the longer leg, c is the hypotenuse.
        // Pythagorean theorem: a^2 + b^2 = c^2
        int a = 3, b = 4, c = 5, i, aMax;
        int maxPerimeter = 1000, maxSolutions = 0, max_i = 0;
        vector<int> solutions{ 0 };

        for (i = 1; i <= maxPerimeter; i++)
                solutions.push_back(0);
        // a's limit: isosceles right triangle, where b has no room to grow.
        aMax = maxPerimeter / (1 + 1 + sqrt(2));
        while (a <= aMax)
        {
                for (b = a + 1; b < maxPerimeter / 2; b++)
                {
                        c = sqrt(a * a + b * b);
                        if (c > maxPerimeter / 2)
                                break;
                        if (a + b + c <= maxPerimeter && a * a + b * b == c * c)
                                solutions[a + b + c]++;
                }
                a++;
        }
        for (i = 0; i <= maxPerimeter; i++)
        {
                if (solutions[i] > maxSolutions)
                        maxSolutions = solutions[i], max_i = i, cout << "found " << maxSolutions << " solutions at perimeter " << max_i << endl;
        }
        cout << "final ans: the max solutions is " << maxSolutions << " at perimeter " << max_i << endl;
        return 0;
}
