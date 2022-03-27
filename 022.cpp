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
		char *st; // name
		size_t val; // sum of letter values
		Node *next; // pointer to next node
};

Node *createnode(char *st)
{
	Node *nodey;
	size_t i;

	nodey = new Node();
	if (!nodey || !st)
		return NULL;
	nodey->st = strdup(st), nodey->next = NULL, nodey->val = 0;
	for (i = 0; i < strlen(nodey->st); i++)
		nodey->val += (nodey->st[i] - 65 + 1); // letter A is the 1st, etc.
	return nodey;
}

void node_connect(Node **head, Node *newnode)
{
	int head_i;
	Node *tmp = NULL, *prev = NULL;

	if (!newnode)
		return;
	head_i = newnode->st[0] - 65; // cap letter to find position in array
	tmp = head[head_i];
	if (!tmp) // 1st node of this letter
		head[head_i] = newnode;
	else // insert into the list and position
	{
		while (tmp && strcmp(newnode->st, tmp->st) > 0)
			prev = tmp, tmp = tmp->next;
		if (!prev)
			head[head_i] = newnode, newnode->next = tmp;
		else
		{
			prev->next = newnode;
			if (tmp)
				newnode->next = tmp;
		}
	}
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
	Node *heads[26], *tmp, *curr = NULL; // heads can be considered as hash table with A-Z algo and sorted linked list
	FILE *fp = fopen("p022_names.txt", "rb");
	char *lines = NULL, *token = NULL, *lsave = NULL;
	ssize_t reading;
	size_t len = 0, i = 0, j, sum = 0, string_val, nth = 1;

	if (fp == NULL)
		exit(EXIT_FAILURE);
	for (j = 0; j < 26; j++) // init
		heads[j] = NULL;
	while ((reading = getline(&lines, &len, fp)) != -1) // making hash table
	{
		token = strtok_r(lines, "\"", &lsave);
		while (token)
		{
			if (token && strcmp(token, ","))
				tmp = createnode(token), node_connect(heads, tmp), i++;
			token = strtok_r(NULL, "\"", &lsave);
		}
	}
	for (j = 0; j < 26; j++) // sum up (string value * position), free nodes
	{
		tmp = NULL, curr = heads[j];
		while (curr)
			tmp = curr, sum += nth * tmp->val, nth++, curr = curr->next, free(tmp->st), free(tmp);
	}
	fclose(fp), cout << i << " names" << endl;
	cout << "final ans: " << sum << endl;
	if (token) // now free everything
		free(token);
	if (lines)
		free(lines);
	return 0;
}
