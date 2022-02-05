#include <stdio.h>
#include <stdlib.h>

/**
 * main - The prime factors of 13195 are 5, 7, 13 and 29.
 *  What is the largest prime factor of the number 600851475143 ?
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	long num = 600851475143, factory = 2;

	while (num % factory > 0)
		factory++;
	while (num % factory == 0)
	{
		num /= factory;
		if (num <= factory)
			break;
		while (num % factory > 0)
			factory++;
	}
	printf("Final ans: %ld\n", factory);
	return (0);
}
