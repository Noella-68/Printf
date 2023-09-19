#include "main.h"
void print_buf(char buf[], int *buf_int);

int _printf(const char *format, ...)

{

int i, printed = 0, printed_chars = 0;

int flags, width, precision, size, buf_int = 0;

va_list lis;

char buf[BUFF_SIZE];

if (format == NULL)

return (-1);

va_start(lis, format);

for (i = 0; format && format[i] != '\0'; i++)

{

if (format[i] != '%')

{

buffer[buf_int++] = format[i];

if (buff_ind == BUFF_SIZE)

print_buf(buffer, &buf_int);



printed_chars++;

}

else

{

print_buf(buffer, &buf_int);

flags = get_flags(format, &i);

width = get_width(format, &i, lis);

precision = get_precision(format, &i, lis);

size = get_size(format, &i);

++i;

printed = handle_print(format, &i, lis, buffer,

flags, width, precision, size);

if (printed == -1)

return (-1);

printed_chars += printed;

}

}



print_buf(buffer, &buf_int);



va_end(lis);



return (printed_chars);

}



void print_buf(char buf[], int *buf_int)

{

if (*buf_int > 0)

write(1, &buffer[0], *buf_int);



*buf_int = 0;

}
