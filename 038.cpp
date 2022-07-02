#include <iostream>
#include <vector>
#include <string>
#include <atomic>

using namespace std;

int first_digit(int num)
{
        int digit = 0;

        while (num)
                digit = num % 10, num = num / 10;
        return digit;
}

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
 * main - Take the number 192 and multiply it by each of 1, 2, and 3:
 *  192 × 1 = 192
 *  192 × 2 = 384
 *  192 × 3 = 576
 *  By concatenating each product we get the 1 to 9 pandigital, 192384576.
 *  We will call 192384576 the concatenated product of 192 and (1,2,3)
 *  The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
 *  and 5, giving the pandigital, 918273645, which is the concatenated product
 *  of 9 and (1,2,3,4,5).
 *  What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 *  the concatenated product of an integer with (1,2, ... , n) where n > 1?
 * Return: 0 if success, 1 otherwise
 */
int main()
{
        int maxBase = 9876, tmp, nextBase, currBase, maxPandigital = 0, i;
        vector<int> hashTable = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        string concat = "";

        currBase = maxBase, nextBase = maxBase;
        while (first_digit(currBase) == 9 && currBase > 8)
        {
                tmp = currBase, concat = "";
                if (unique_int(currBase) == 0)
                {
                        while (concat.length() < 9)
                                concat += to_string(tmp), tmp += currBase;
                        hashTable = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                        if (concat.length() == 9)
                        {
                                for (i = 0; i < 10; i++)
                                        hashTable[concat[i] - '0']++;
                                for (i = 0; i < 10; i++)
                                {
                                        if (hashTable[i] != 1)
                                                break;
                                }
                                if (i == 10)
                                        cout << "Pandigital string that starts with 9: " << concat << " at base number " << currBase << endl;
                                if (i == 10 && stoi(concat) > maxPandigital)
                                        maxPandigital = stoi(concat);
                        }
                }
                currBase--;
                if (first_digit(currBase) < 9)
                        nextBase /= 10, currBase = nextBase;
        }
        cout << "final ans: " << maxPandigital << endl;
        return 0;
}
