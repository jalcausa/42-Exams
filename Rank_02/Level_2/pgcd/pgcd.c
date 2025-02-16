#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int n1 = atoi(argv[1]);
		int n2 = atoi(argv[2]);
		int n = 0;

		if (n1 <= n2)
			n = n1;
		else
			n = n2;
		while (n > 0)
		{
			if (n1 % n == 0 && n2 % n == 0)
			{
				printf("%i\n", n);
				return (0);
			}
			--n;
		}
	}
	write(1, "\n", 1);
	return (0);
}
