#include "shell.h"
/**
 * print_number -Print Unsigned Int Putchar
 * displays an int to
 * screen
 * @n: Unisigned Integer
 * Return: Void
 */
void print_number(unsigned int n)
{
	unsigned int u = n;

	if ((u / 10) > 0)
		print_number(u / 10);

	_putchar(u % 10 + '0');
}
/**
 * print_number_in -Print Number Putchar
 * @n:Integer
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int u = n;

	if (u < 0)
	{
		_putchar('-');
		u = -u;
	}
	if ((u / 10) > 0)
		print_number(u / 10);

	_putchar(u % 10 + '0');
}
