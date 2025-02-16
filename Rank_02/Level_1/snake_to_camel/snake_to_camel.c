#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char c = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
			{
				++i;
				c = argv[1][i];
				if (c >= 'a' && c <= 'z')
					 c-=32;
				write(1, &c, 1);
				++i;
			}
			else
			{
				write(1, &argv[1][i++], 1);
			}
		}
	}
	write(1, "\n", 1);
}
