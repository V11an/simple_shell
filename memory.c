#include "shell.h"

/**
 * bfree - free pointer and NULL's the address
 * @ptr: the address of ptr to free
 *
 * Return: 1 if freed else 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
