#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move past the %
            if (*format == 'c') {
                // Handle the %c specifier
                char c = va_arg(args, int); // Characters are promoted to int when passed as variable arguments
                putchar(c);
                char_count++;
            } else if (*format == 's') {
                // Handle the %s specifier
                char *str = va_arg(args, char *);
                while (*str) {
                    putchar(*str);
                    str++;
                    char_count++;
                }
            } else if (*format == '%') {
                // Handle the %% specifier (literal %)
                putchar('%');
                char_count++;
            }
        } else {
            putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}

int main() {
    int count = _printf("Hello, %s! The answer is %d%%.\n", "world", 42);
    printf("Characters printed: %d\n", count);
    return 0;
}