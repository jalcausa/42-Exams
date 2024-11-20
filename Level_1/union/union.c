#include <unistd.h>

int	is_in(char c, char *str)
{
	int i = 0;
	
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		++i;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = 0;
		char res[ft_strlen(argv[1]) + ft_strlen(argv[2])];
		while (argv[1][i])
		{
			if (!is_in(argv[1][i], res))
				res[j++] = argv[1][i++];
			else
				++i;
		};
		i = 0;
		while (argv[2][i])
		{	
			if (!is_in(argv[2][i], res))
				res[j++] = argv[2][i++];
			else
				++i;
		}
		j = 0;
		while (res[j])
			write(1, &res[j++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
