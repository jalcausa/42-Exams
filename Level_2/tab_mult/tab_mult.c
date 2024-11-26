#include <unistd.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		++i;
	}
	return (res);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr (n % 10);
	}
	else
	{
		char c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_print(int *tab, int size)
{
	int i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i++]);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int base[] = {1,2,3,4,5,6,7,8,9};
		int n = ft_atoi(argv[1]);
		int res[9];
		char c = 0;
		
		int i = 0;
		while (i < 9)
		{
			res[i] = base[i] * n;
			++i;
		}
		i = 0;
		while (i < 9)
		{
			ft_putnbr(base[i]);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(res[i]);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
