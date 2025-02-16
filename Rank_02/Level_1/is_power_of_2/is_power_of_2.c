int	is_power_of_2(unsigned int n)
{
	int i = 2;
	if (n == 1 || n == 2)
		return (1);
	while (i*2 <= n)
	{
		if (i*2 == n)
			return (1);
		i*=2;
	}
	return (0);
}

/*
Otra forma de hacerlo:

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return ((n & (n - 1)) == 0);
}

int	main(void)
{
	int n = 8;
	int is_power = is_power_of_2(n);
	if (is_power)
		printf("Es potencia de dos\n");
	else
		printf("No es potencia de dos\n");
	return (0);
}
*/
