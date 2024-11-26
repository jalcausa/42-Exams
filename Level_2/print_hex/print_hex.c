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

void	ft_puthex(int n, char *str)
{
	if (n > 15)
	{
		ft_puthex(n / 16, str);
		ft_puthex(n % 16, str);
	}
	else
	{
		write(1, &str[n], 1);
	}	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *alphabet = "0123456789abcdef";
		int n = ft_atoi(argv[1]);
		ft_puthex(n, alphabet);
	}
	write(1, "\n", 1);
	return (0);
}
