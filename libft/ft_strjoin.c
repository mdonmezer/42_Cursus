#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *s_son;
	int i;
	int j;

	s_son = malloc(sizeof(char) * (ft_strlen(s1) * ft_strlen(s2) + 1));

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		s_son[j++] = s1[i++];

	i = 0;
	while (s2[i] != '\0')
		s_son[j++] = s2[i++];

	s_son[j] = '\0';

	return (s_son);
}
