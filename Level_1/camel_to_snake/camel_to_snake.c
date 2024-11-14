#include <unistd.h>

int	is_upper(char c)
{
	if (!(c>='A' && c<='Z'))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char c = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (is_upper(c))
			{
				write(1, "_", 1);
				c = c + 32;
				write(1, &c, 1);
			}
			else
			{
				write(1, &c, 1);
			}
			++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}
