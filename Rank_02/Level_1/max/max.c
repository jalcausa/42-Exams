//#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int max = 0;
	unsigned int i = 0;

	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		++i;
	}
	return (max);
}
/*
int	main(void)
{
	int res[] = {2,1,5,6};
	int m = max (res, 4);
	printf ("El máximo es: %i\n", m);
	return (0);
}
*/
