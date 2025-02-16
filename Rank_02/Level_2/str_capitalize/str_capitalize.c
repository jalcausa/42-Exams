#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (1);
	return (0);
}

void	str_capitalizer(char *str)
{
	int i = 0;
	
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -=32;
	write(1, &str[i], 1);
	++i;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && is_space(str[i - 1]))
			str[i] -= 32;
		write(1, &str[i], 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
