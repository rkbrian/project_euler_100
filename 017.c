#include <stdio.h>
#include <stdlib.h>

/**
 * main - If the numbers 1 to 5 are written out in words: one, two, three,
 *  four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *  If all the numbers from 1 to 1000 (one thousand) inclusive were written
 *  out in words, how many letters would be used?
 *  Do not count spaces or hyphens. For example, 342 (three hundred and
 *  forty-two) contains 23 letters and 115 (one hundred and fifteen) contains
 *  20 letters. The use of "and" when writing out numbers is in compliance
 *  with British usage.
 * Return: 0 if success, 1 if fail
 */
int main(void)
{
	int sings[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};/*1-9*/
	int teens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};/*10-19*/
	int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};/*20, 30, 40... 90*/
	int hunds[] = {7, 10};/*-hundred, -hundred and-*/
	int thous = 11;/*finish line*/
	int i = 0, sum = 0, tmp = 0;

	for (i = 0; i < 9; i++) /*1-9*/
		tmp += sings[i];
	sum += tmp * 9; /*singles in 100*/
	for (i = 0; i < 10; i++) /*complete 20-99*/
		sum += 10 * tens[i];
	for (i = 0; i < 10; i++) /*oddballs*/
		sum += teens[i];
	printf("Checking 1-99: %d, good\n", sum);
	sum = sum * 10; /*2 digits in 1000, 000's to 900's*/
	sum += tmp * 100 + hunds[0] * 9 + hunds[1] * 99 * 9; /*1-999*/
	sum += thous;
	printf("Final ans: %d\n", sum);
	return (0);
}
