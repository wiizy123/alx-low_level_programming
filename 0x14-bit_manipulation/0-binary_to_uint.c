#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* binary_to_uint - Converts a binary number to an unsigned integer.
* @b: A pointer to the string containing the binary number.
* Return: The converted number, or 0 if b is NULL or if the string contains
* characters other than '0' and '1'.
*/

unsigned int binary_to_uint(const char *b)
{
    unsigned int num = 0;

    if (b == NULL)
        return 0;

    for (; *b; b++)
    {
        if (*b != '0' && *b != '1')
            return 0;

        num = num * 2 + (*b - '0');
    }

    return num;
}

