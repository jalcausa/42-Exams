#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		++i;
	return (i);
}

char	*rev_print(char *str)
{
	int i = ft_strlen(str);
	while (i>=0)
	{
		write(1, &str[i], 1);
		--i;
	}
	write(1, "\n", 1);
	return (str);
}

int	main(void)
{
	rev_print("Hello world");
	return (0);
}
