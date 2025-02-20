#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putstr(char *str)
{
	int i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	char *base = "0123456789";
	int count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		++count;
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += write(1, &base[n % 10], 1);
	return (count);
}

int	ft_puthex(unsigned int n)
{
	char *base = "0123456789abcdef";
	int count = 0;
	if (n > 15)
		count += ft_puthex(n / 16);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int i = 0;
	int c = 0;
	va_list arg;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			++i;
			if (str[i] == 's')
				c += ft_putstr(va_arg(arg, char *));
			else if (str[i] == 'd')
				c += ft_putnbr(va_arg(arg, int));
			else if (str[i] == 'x')
				c += ft_puthex(va_arg(arg, unsigned int));
			++i;
		}
		else
		{
			write(1, &str[i], 1);
			++i;
			++c;
		}
	}
	va_end(arg);
	return (c);
}

int main (void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}
