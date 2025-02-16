#include <unistd.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		char c = n + '0';
		write(1, &c, 1);
	}
}

int	is_prime(int n)
{
	int i = 2;
	if (n < 2)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int	add_prime_sum(int n)
{
	int i = n;
	int res = 0;
	
	while (i >= 2)
	{
		if (is_prime(i))
			res+=i;
		--i;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int n;
	if (argc == 2 && (n = ft_atoi(argv[1])))
	{
		ft_putnbr(add_prime_sum(n));
	}
	else if (argc != 2 || ft_atoi(argv[1]))
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
