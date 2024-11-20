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

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		++i;
	return(i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *first = argv[1];
		char *second = argv[2];
		char res[ft_strlen(first) + 1];
		int i = 0;
		int j = 0;
		int k = 0;

		while (first[i] && second[j])
		{
			if (is_in(first[i], second) && !is_in(first[i], res))
			{
				res[k] = first[i];
				++k;
				res[k] = '\0';
			}
			++i;
			++j;
		}
		res[k] = '\0';
		k = 0;
		while (res[k])
		{
			write(1, &res[k], 1);
			++k;
		}
	}
	write(1, "\n", 1);
	return (0);
}
