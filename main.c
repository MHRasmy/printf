#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Printf function
 * @format: format string.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, num_printed = 0, total_printed = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list arg_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
			{
				print_buffer(buffer, &buffer_index);
			}
			total_printed++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, arg_list);
			precision = get_precision(format, &i, arg_list);
			size = get_size(format, &i);
			++i;
			num_printed = handle_print(format, &i, arg_list, buffer,
					flags, width, precision, size);
			if (num_printed == -1)
			{
				return (-1);
			}
			total_printed += num_printed;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(arg_list);

	return (total_printed);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters.
 * @buffer_index: Index at which to add next character, represents the length.
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, &buffer[0], *buffer_index);
	}

	*buffer_index = 0;
}
