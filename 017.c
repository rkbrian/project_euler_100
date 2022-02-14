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
	int sings[] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3};/*1-10*/
	int teens[] = {6, 6, 8, 8, 7, 7, 9, 8, 8};/*11-19*/
	int tens[] = {6, 6, 5, 5, 5, 7, 6, 6};/*20, 30, 40... 90*/
	int hunds[] = {7, 10};/*-hundred, -hundred and-*/
	int thous[] = 11;/*finish line*/
	int i = 0, sum = 0;

	/**/
}
