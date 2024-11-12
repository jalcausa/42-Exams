#include <unistd.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i]<= 'z')
			{
				int j = argv[1][i] - 'a';
				while(j >= 0)
				{
					write(1, &argv[1][i], 1);
					--j;
				}
			}
			else if (argv[1][i] >= 'A' && argv[1][i]<= 'Z')
                        {
                                int j = argv[1][i] - 'A';
                                while(j >= 0)
                                {
                                        write(1, &argv[1][i], 1);
                                        --j;
                                }
                        }
			else
				write(1, &argv[1][i], 1);
			++i;
			
		}
	}
	write(1, "\n", 1);
}
