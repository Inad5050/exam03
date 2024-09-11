#include <stdarg.h>
#include <unistd.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_digit(long long int nbr, int base, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_digit((nbr / base), base, len);
	*len += write(1, &hexa[nbr % base], 1);
}

int	ft_printf(const char *str, ...)
{
	int			len = 0;
	va_list		arg;

	va_start(arg, str);
	while (*str)
	{
		if ((*str == '%') && *(str + 1))
		{
			str++;
			if (*str == 's')
				put_str(va_arg(arg, char *), &len);
			else if (*str == 'd')
				put_digit((long long int)va_arg(arg, int), 10, &len);
			else if (*str == 'x')
				put_digit((long long int)va_arg(arg, unsigned int), 16, &len);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(arg);
	return (len);
}