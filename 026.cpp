#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <atomic>

using namespace std;

/**
 * main - A unit fraction contains 1 in the numerator. The decimal
 *  representation of the unit fractions with denominators 2 to 10 are given:
 *  1/2 = 0.5
 *  1/3 = 0.(3)
 *  1/4 = 0.25
 *  1/5 = 0.2
 *  1/6 = 0.1(6)
 *  1/7 = 0.(142857)
 *  1/8 = 0.125
 *  1/9 = 0.(1)
 *  1/10 = 0.1
 *  Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
 *  It can be seen that 1/7 has a 6-digit recurring cycle.
 *  Find the value of d < 1000 for which 1/d contains the longest recurring
 *  cycle in its decimal fraction part.
 * Return: 0 if success, 1 if fail
 */
int main()
{
        long divisor = 1, dividend = 2, remainder = 0, d_limit = 1000, longest_d = 0, d = 0;
        map <int, int> digimap; // collection of (remainder, iterator), i increment from 0
        vector<char> recur_cyc;
        // vector<char> targ;

        while (dividend < d_limit)
        {
                remainder = divisor % dividend;
                while (remainder)
                {
                        if (!digimap.empty() && (digimap.find(remainder) != digimap.end()))
                        {
                                recur_cyc.insert(recur_cyc.begin() + digimap[remainder], '(');
                                recur_cyc.push_back(')');
                                recur_cyc.erase(recur_cyc.begin(), recur_cyc.begin() + digimap[remainder]);
                                if (recur_cyc.size() - 2 > longest_d)
                                {
                                        cout << string(recur_cyc.begin(), recur_cyc.end()) << endl;
                                        longest_d = recur_cyc.size() - 2, d = dividend;
                                }
                                break;
                        }
                        else
                        {
                                digimap[remainder] = recur_cyc.size();
                                remainder *= 10;
                                recur_cyc.push_back((remainder / dividend) + '0');
                                remainder = remainder % dividend;
                        }
                }
                dividend++, digimap.clear(), recur_cyc.clear();
        }
        // cout << "the longest recuring cycle: " << string(targ.begin(), targ.end()) << endl;
	cout << "final ans: " << d << endl;
        return 0;
}
