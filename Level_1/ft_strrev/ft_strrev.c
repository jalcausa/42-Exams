#include <stdio.h>

char	*ft_strrev(char *str)
{
	int	len = 0;
	int	i = 0;
	char	tmp;

	while (str[len])
		++len;
	len--;
	while (i<len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		++i;
		--len;
	}
	return (str);
}

int	main(void)
{
	char string[] = "Hola";
	printf("String original: %s\n", string);
	char *res = ft_strrev(string);
	printf("String invertido: %s\n", string);
	return (0);
}
