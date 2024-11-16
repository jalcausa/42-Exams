#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strdup(char *src)
{
	int 	i = 0;
	int 	len = ft_strlen (src);
	char	*res;
 
	res = (char *)malloc((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = src[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
