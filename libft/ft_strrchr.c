#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t len;
	len = ft_strlen(str);

	while (len + 1 > 0)
	{
		if (str[len] == (char)c)
			return (char *)(str + len);
		len--;
	}
	if (c == 0)
		return ((char *)(str + len));

	return (NULL);
}
