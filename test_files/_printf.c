#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);	
	int char_count = 0;
	
	while (*format)
	{
		if (*format == '%')
		{
			format++; // Move past the %
			// Handle conversion specifiers here
			if (*format == 'd')
			{
				char val = va_arg(args, int);
				putchar(val);
				// Update char_count accordingly
				char_count++;
			}
			else if (*format == 'f')
			{
				char val = va_arg(args, double);
				putchar(val);
				char_count++;
			}
			else if(*format == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					putchar(*str);
					*str++;
					char_count++;
				}
			}
		else
		{
			putchar(*format);
			char_count++;	
		}
		}
	format++;
	}	
	va_end(args);
	return char_count;
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
int main() {
	int count = _printf("Hello, %s! The answer is %d%%.\n", "world", 42);
	
	printf("Characters printed: %d\n", count);
	return 0;
}
