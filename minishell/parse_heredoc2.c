/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:11:04 by beergin           #+#    #+#             */
/*   Updated: 2025/08/13 12:28:49 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_expandable_delim(int quote_type)
{
	if (quote_type == 1 || quote_type == 2)
		return (0);
	return (1);
}

char	*expand_variables2(char *line, t_shell *shell)
{
	char	*expanded;

	if (!line || !shell)
		return (NULL);
	expanded = expand_string(line, shell);
	return (expanded);
}

void	write_heredoc_line(int fd, char *line, int expand, t_shell *shell)
{
	char	*expanded;

	if (expand)
		expanded = expand_variables2(line, shell);
	else
		expanded = ft_strdup(line);
	write(fd, expanded, ft_strlen(expanded));
	write(fd, "\n", 1);
	free(expanded);
}

static int	heredoc_child(t_command *cmd, t_shell *shell, t_heredoc *hd)
{
	close(hd->pipe_fd[0]);
	hd->expand = 1;
	while (1)
	{
		hd->line = readline("> ");
		if (!hd->line)
			break ;
		if (ft_strncmp(hd->line, cmd->heredoc_delimiter,
				ft_strlen(cmd->heredoc_delimiter)) == 0
			&& ft_strlen(hd->line) == ft_strlen(cmd->heredoc_delimiter))
		{
			free(hd->line);
			break ;
		}
		write_heredoc_line(hd->pipe_fd[1], hd->line, hd->expand, shell);
		free(hd->line);
	}
	close(hd->pipe_fd[1]);
	return (0);
}

int	execute_heredoc(t_command *cmd, t_shell *shell)
{
	t_heredoc	hd;

	if (!cmd->heredoc_delimiter)
		return (0);
	if (pipe(hd.pipe_fd) == -1)
		return (perror("heredoc pipe"), -1);
	hd.pid = fork();
	if (hd.pid == -1)
	{
		perror("heredoc fork");
		close(hd.pipe_fd[0]);
		close(hd.pipe_fd[1]);
		return (-1);
	}
	if (hd.pid == 0)
	{
		if (heredoc_child(cmd, shell, &hd) == 0)
			exit(0);
		exit(1);
	}
	return (heredoc_parent(cmd, &hd));
}
