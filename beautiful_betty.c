#include <stdio.h>

/**
 * print_hello - Prints "Hello" to the standard output.
 *
 * Description: prints the message "Hello" .
 */

void print_hello(void)
{
	printf("Hello\n");
}

/**
 * main - Entry point of the program.
 *
 * Description: This is the main function of the program. It calls
 * the print_hello function to print "Hello" to the standard output.
 *
 * Return: 0 on success.
 */

int main(void)
{
	print_hello();
	return (0);
}
