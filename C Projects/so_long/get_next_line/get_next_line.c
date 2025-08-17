/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:40:47 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 07:53:06 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char	*readone)
{
	char	*buff;
	int		count;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	count = 1;
	while (!ft_strchr(readone, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			free(readone);
			return (NULL);
		}
		buff[count] = '\0';
		readone = ft_strjoin(readone, buff);
	}
	free(buff);
	return (readone);
}

char	*put(char *readone)
{
	char	*str;
	int		i;

	i = 0;
	if (!readone[i])
		return (NULL);
	while (readone[i] != '\n' && readone[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (readone[i] != '\n' && readone[i] != '\0')
	{
		str[i] = readone[i];
		i++;
	}
	if (readone[i] == '\n')
	{
		str[i] = readone[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*nextline(char *readone)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (readone[i] != '\n' && readone[i] != '\0')
		i++;
	if (!readone[i])
	{
		free(readone);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(readone) - i));
	if (!str)
		return (NULL);
	i++;
	while (readone[i + j] != '\0')
	{
		str[j] = readone[j + i];
		j++;
	}
	str[j] = '\0';
	free(readone);
	return (str);
}

static void	clean_static_buffer(char **buffer)
{
	if (*buffer && (*buffer)[0] == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*readone = NULL;
	char		*arr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readone = readline(fd, readone);
	if (!readone)
		return (NULL);
	arr = put(readone);
	if (!arr)
	{
		free(readone);
		readone = NULL;
		return (NULL);
	}
	readone = nextline(readone);
	clean_static_buffer(&readone);
	return (arr);
}
