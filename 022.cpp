#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <limits.h>
#include <unistd.h>
#include <atomic>

using namespace std;

class Node {
	public:
		string st;
		Node *next;
};

Node *createnode(char *st)
{
	Node *nodey;

	nodey = new Node();
	if (!nodey || !st)
		return NULL;
	nodey->st = strdup(st), nodey->next = NULL;
        return nodey;
}

void node_connect(Node *head, Node *newnode)
{
	if (!newnode)
		return;
	if (!)
}

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
	Node *heads[26], *tmp;
	FILE *fp = fopen("p022_names.txt", "rb");
	char *lines = NULL, *token = NULL, *lsave = NULL;
	char *totoken = NULL, *sublsave = NULL;
	ssize_t reading;
	size_t len = 0;
	long i, j, size = 0, **arr, sum = 0, triangle_size = 15;

	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		token = strtok_r(lines, ",", &lsave);
		if (token)
			tmp = createnode(token);
	}
	
	return 0;
}
