int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;
	char c = 0;
	
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	while (str[i])
	{
		c = str[i];
		if (c >= 'A' && c <= 'F')
			c = c + 32;
		if (c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'a' && c <= 'f')
			c = c - 'a' + 10;
		else
			return (0);
		if (c >= str_base)
			return (0);
		res = res * str_base + c;
		++i;
	}
	return (res * sign);
}
/*
#include <stdio.h>
int main()
{
	const char *str = "24";
	int str_base = 5;
	int s = ft_atoi_base(str, str_base);
	printf("%d\n", s);
	printf("%d\n", ft_atoi_base("101", 2)); // 5 en decimal
	printf("%d\n", ft_atoi_base("A", 16));  // 10 en decimal
	printf("%d\n", ft_atoi_base("24", 5));  // 14 en decimal
	return (0);
}
*/
