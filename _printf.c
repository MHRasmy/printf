#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - printing the charachters and according to the
 *  specifier that exists, prints the value of the variable
 * 
 * @*format: the first argument and the sequance that will be
 * checked for specifiers
 * 
 * @...: unspecified number of argument that will be checked
 * 
 * return: number of charachers printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					char c = (char) va_arg(args, int);

					write(1, &c, 1);
					count++;
					break;
				case 's':
					char *str = va_arg(args, char *);
					while (*str != '\0')
					{
						write(1, str, 1);
						str++;
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
