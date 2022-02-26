#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

long max_val(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

long recur_path(long **arr, long triangle_size)
{
	long i, j, size = 2, ret_val = 0;

	for (i = 1; i < size; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j > 0 && j < i)
				arr[i][j] += max_val(arr[i - 1][j], arr[i - 1][j - 1]);
			else if (j == i)
				arr[i][j] += arr[i - 1][j - 1];
			else if (j == 0)
				arr[i][j] += arr[i - 1][j];
			printf("%4ld,", arr[i][j]);
		}
		printf("\n");
		if (size < triangle_size)
			size++;
	}
	for (j = 0; j < triangle_size; j++)
		ret_val = max_val(arr[triangle_size - 1][j], ret_val);
	return (ret_val);
}

/**
 * main - By starting at the top of the triangle below and moving to adjacent
 *  numbers on the row below, the maximum total from top to bottom is 23.
 *  3
 *  7 4
 *  2 4 6
 *  8 5 9 3
 *  That is, 3 + 7 + 4 + 9 = 23.
 *  Find the maximum total from top to bottom of a large triangle.
 * NOTE: As there are only 16384 routes, it is possible to solve this problem
 *  by trying every route. However, Problem 67, is the same challenge with a
 *  triangle containing one-hundred rows; it cannot be solved by brute force,
 *  and requires a clever method! ;o)
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	FILE *fp = fopen("txt_018.txt", "rb");
	char *lines = NULL, *token = NULL, *lsave = NULL;
	char *totoken = NULL, *sublsave = NULL;
	ssize_t reading;
	size_t len = 0;
	long i, j, size = 0, **arr, sum = 0, triangle_size = 15;

	if (fp == NULL)
		exit(EXIT_FAILURE);
	arr = malloc(sizeof(long *) * triangle_size);
	for (i = 0; i < triangle_size; i++)
		arr[i] = malloc(sizeof(long) * triangle_size);
	for (i = 0; i < triangle_size; i++)
		memset(arr[i], 0, triangle_size * sizeof(long));
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		token = strtok_r(lines, "\n", &lsave);
		if (token)
		{
			totoken = strtok_r(token, " ", &sublsave);
			for (j = 0; j <= size; j++)
			{
				arr[size][j] = (totoken[0] - 48) * 10 + (totoken[1] - 48), printf("%3ld,", arr[size][j]);
				totoken = strtok_r(NULL, " ", &sublsave);
			}
			size++;
			printf("\n");
		}
	}
	fclose(fp), sum = recur_path(arr, triangle_size);
	printf("Final ans: %lu\n", sum);
	if (token)
		free(token);
	for (i = 0; i < triangle_size; i++)
		free(arr[i]);
	free(arr);
	return (0);
}
