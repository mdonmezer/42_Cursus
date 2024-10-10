#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			j = 0;
			while (s1[i] == s2[j] && s2[j] != '\0' || s1[i] != '\0')
			{
				j++;
				i++;
			}
			if (s2[j] == '\0')
				return (char *)(&s1[i-j]);
		}
		i++;
	}
	return (NULL);

}
