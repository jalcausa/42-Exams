#include <stdlib.h>
//#include <stdio.h>

int	is_in(char c, const char *str)
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

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	while (s[i] && !is_in(s[i], reject))
		++i;
	return (i);
}
/*
int main()
{
    const char *s = "hhhello world";
    const char *reject = "aeiou"; // Vocales

    size_t result = ft_strcspn(s, reject);

    printf("Segmento inicial sin vocales: %zu\n", result);
    return 0;
}
*/
