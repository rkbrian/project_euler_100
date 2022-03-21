#include <iostream>
#include <string>
#include <fstream>
#include <atomic>

using namespace std;

class Node {
        public:
        string st;
        Node *next;
};

/**
 * main - Using names.txt, a 46K text file containing over 5000 first names,
 *  begin by sorting it into alphabetical order. Then working out the
 *  alphabetical value for each name, multiply this value by its alphabetical
 *  position in the list to obtain a name score.
 *  For example, when the list is sorted into alphabetical order, COLIN, which
 *  is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
 *  So, COLIN would obtain a score of 938 × 53 = 49714.
 *  What is the total of all the name scores in the file?
 * Return: 0 if success, 1 if fail
 */
int main()
{
        ifstream infile;
        Node *heads

        infile.open("p022_names.txt");
        return 0;
}
