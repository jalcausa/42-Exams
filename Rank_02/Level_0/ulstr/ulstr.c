#include <unistd.h>

int	ft_is_lower(char c)
{
	if(!(c >='a' && c<= 'z'))
		return (0);
	return (1);
}

int	ft_is_upper(char c)
{
	if(!(c >='A' && c<= 'Z'))
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
			if (ft_is_upper(argv[1][i]))
				c = argv[1][i] + 32;
			else if (ft_is_lower(argv[1][i]))
				c = argv[1][i] - 32;
			else
				c = argv[1][i];
			write(1, &c, 1); 
			++i;
		}
	}
	write(1, "\n", 1);
}
