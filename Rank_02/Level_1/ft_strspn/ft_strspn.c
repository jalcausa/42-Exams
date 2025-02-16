int	is_in_accept(char c, char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] && is_in_accept(s[i], accept))
		++i;
	return (i);
}
