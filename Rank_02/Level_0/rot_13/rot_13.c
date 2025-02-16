#include <unistd.h>

int	is_alpha_lower(char c)
{
	if (!(c>='a' && c<='z'))
		return (0);
	return (1);
}

int     is_alpha_upper(char c)
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
		while(argv[1][i])
		{
			if (is_alpha_lower(argv[1][i]))
			{
				char n = ((argv[1][i] - 'a' + 13) % 26) + 'a';
				write(1, &n, 1);
			}
			else if (is_alpha_upper(argv[1][i]))
                        {
                                char n = ((argv[1][i] -'A' + 13) % 26) + 'A';
                                write(1, &n, 1);
                        }

			else
			{
				write(1, &argv[1][i], 1);
			}
			++i;
		}
	}
	write(1, "\n", 1);
}
