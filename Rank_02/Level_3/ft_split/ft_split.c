#include <stdlib.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_count_words(char *str)
{
	int i = 0;
	int res = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			++i;
		if (str[i])
			++res;
		while (str[i] && !is_space(str[i]))
			++i;
	}
	return (res);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}

char	**ft_split(char *str)
{
	char	**res;
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	wc = 0;

	wc = ft_count_words(str);
	char **res = (char **)malloc(sizeof(char *) * (wc + 1));
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			++i;
		j = i;
		while (str[i] && !is_space(str[i]))
			++i;
		if (i > j)
		{
			res[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(res[k], &str[j], i-j);
			++k;
		}
	}
	res[k] = NULL;
	return (res);
}
