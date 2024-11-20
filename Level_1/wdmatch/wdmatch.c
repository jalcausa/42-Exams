#include <unistd.h>

int	possible (char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int res = 0;
	
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				++j;
				break;
			}
			++j;
		}
		if (s2[j] == '\0')
			return 0;
		++i;
	}
	return 1;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		if (possible(argv[1], argv[2]))
		{
			while (argv[1][i])
				write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
