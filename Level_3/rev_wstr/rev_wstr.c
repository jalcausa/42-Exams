#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		++i;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = ft_strlen(argv[1]) - 1;
		int i = 0;
		while (n >= 0)
		{
			while (n >= 0 && argv[1][n] != ' ')
				--n;
			i = n + 1;
			while (argv[1][i] && argv[1][i] != ' ')
			{
				write(1, &argv[1][i], 1);
				++i;
			}
			if (n > 0)
				write(1, " ", 1);
			--n;
		}
	}
	write(1, "\n", 1);
	return (0);
}
