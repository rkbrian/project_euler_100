#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

/**
 * main - Work out the first ten digits of the sum of
 *  one-hundred 50-digit numbers.
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	FILE *fp = fopen("txt_013.txt", "rb");
	char *lines = NULL, *token = NULL, *lsave = NULL;
	ssize_t reading;
	size_t len = 0;
	long i, j = 0, digi_size = 13, valid_ds = 10, x = 1, arr[digi_size];

	if (fp == NULL)
		exit(EXIT_FAILURE);
	memset(arr, 0, digi_size * sizeof(arr[0]));
	while ((reading = getline(&lines, &len, fp)) != -1)
	{
		token = strtok_r(lines, "\n", &lsave);
		if (token)
		{
			for (i = 0; i < digi_size; i++)
				arr[i] += (token[i] - 48);
		}
	}
	fclose(fp);
	for (i = 0; i < digi_size; i++)
		j += arr[i], j *= 10;
	i = 0;
	while (i < valid_ds)
		x *= 10, i++;
	while (j > x)
		j /= 10;
	printf("Final ans: %ld\n", j);
	return (0);
}
