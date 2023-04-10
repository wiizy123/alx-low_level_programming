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
	unsigned long int p = 2, b = 0;
	int i;
	
	for (i = 0; p <= n && i < 62; i++)
	{
		p = p << 1;
	}

	if (i != 62)
		p = p >> 1;

	for (; p != 0; p = p >> 1)
	{
		b = n & p;

		switch (b)
		{
			case 0:
				_putchar('0');
				break;

			case 1:
				_putchar('1');
				break;
		}
	}
}
