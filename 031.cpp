#include <iostream>
#include <cstring>
#include <atomic>

using namespace std;

size_t buffer[20][300]; // dynamic programming table,
// [length of coins array][total value] to store number of coins to be used

/**
 * recur_change - recursion to count coin denomination combinations
 * @arr: coins array
 * @coin_i: iteration in coins
 * @goal: total or subtotal the combination is targeting
 * @size: size of currrency array
 * Return: number of coins needed
 */
size_t recur_change(size_t *arr, size_t coin_i, size_t goal, size_t size)
{
        size_t i, count = 0;

        if (buffer[coin_i][goal]) // add on!
                return buffer[coin_i][goal];
        if (coin_i == size) // time to return
        {
                if (!goal) // subtotal cleared
                        return 1;
                return 0;
        }
        for (i = 0; i * arr[coin_i] <= goal; i++) // branching out
                count += recur_change(arr, coin_i + 1, goal - i * arr[coin_i], size);
        buffer[coin_i][goal] = count; // add on!
        return count;
}

/**
 * main - In the United Kingdom the currency is made up of pound (£) and
 *  pence (p). There are eight coins in general circulation:
 *  1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
 *  It is possible to make £2 in the following way:
 *  1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 *  How many different ways can £2 be made using any number of coins?
 * Note: this is a case of reachable number and perfect denominations.
 * Return: 0 if success, 1 if fail
 */
int main()
{
        size_t coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
        size_t goal = 200, sum = 0, size;

        memset(buffer, 0, sizeof(buffer)); // add on!
        size = sizeof(coins) / sizeof(size_t);
        sum = recur_change(coins, 0, goal, size);
        cout << "final ans: " << sum << endl;
        return 0;
}
