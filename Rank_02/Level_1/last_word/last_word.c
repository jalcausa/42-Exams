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
		int i = ft_strlen(argv[1]) - 1;
		while (i>= 0  && argv[1][i] != ' ' && argv[1][i] != '\t')
			--i;
		char *p = &argv[1][i+1];
		while (*p)
		{
			write(1, p, 1);
			++p;
		}
	}
	write(1, "\n", 1);
	return (0);
}
