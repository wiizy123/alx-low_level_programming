#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary
 * Description: This function prints the binary representation of a given number
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int len = 0;

	while ((n >> len) > 0)
		len++;

	len--;

	while (len >= 0)
	{
		if ((n & (mask << len)) == 0)
			_putchar('0');
		else
			_putchar('1');

		len--;
	}
}
