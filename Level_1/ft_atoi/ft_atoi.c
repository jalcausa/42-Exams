int	ft_atoi(const char str)
{
	int	i = 0;
	int	res = 0;
	int	sign = 1;
	
	while ((str[i] >= '\t' && str[i] < '\r') || str[i] == ' ')
	{
		++i;
	}
	if (str[i] == '-')
	{
		sign*=-1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] == '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		++i;
	}
	return (res*sign);
}
