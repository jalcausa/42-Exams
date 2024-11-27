#include <stdlib.h>

int	ft_len(int n)
{
	int i = 0;

	if (n < 0)
		++i;
	while (n != 0)
	{
		++i;
		n = n / 10;
	}
	return (i);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int nbr)
{
	char *res;
	int len;

	len = ft_len(nbr);
	res = (char *)(malloc(sizeof(char) * (len + 1)));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
		res[0] = '-';
	else if (nbr == 0)
		res[0] = '0';
	while (nbr != 0)
	{
		--len;
		res[len] = ft_abs(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (res);
}

/*
#include <stdio.h>
 #include <limits.h>

 int	main(void)
  {
	 	int d = INT_MIN;
  	printf("%d =? %s\n", d, ft_itoa(d));

 	d = -14;
	 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = 0;
	 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = 5;
	 	printf("%d =? %s\n", d, ft_itoa(d));

 	d = INT_MAX;
	 	printf("%d =? %s\n", d, ft_itoa(d));
	 }
*/
