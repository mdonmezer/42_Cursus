#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			write (fd, &str[i], 1);
			i++;
		}
	}
	write(fd, "\n", 1);
}
