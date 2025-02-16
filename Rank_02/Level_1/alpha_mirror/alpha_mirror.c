#include <unistd.h>

int is_lower(char c)
{
	if (!(c>='a' && c<='z'))
		return(0);
	return (1);
}

int is_upper(char c)
{
        if (!(c>='A' && c<='A'))
                return(0);
        return (1);
}

int	main(int argc, char **argv)
{
	char c = 0;
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (is_lower(c))
				c = 'z' - (c - 'a');
			else if (is_upper(c))
				c = 'Z' - (c - 'A');
			write(1, &c, 1);
			++i;
		}
	}
	write(1, "\n", 1);
}
