#include "main.h"
#include <stdio.h>
/**
 * set_string - Sets the value of a pointer to a char.
 * @s: Double pointer to a char to be set.
 * @to: Pointer to a char whose value will be set to *s.
 */
void set_string(char **s, char *to)
{
    *s = to;
}

