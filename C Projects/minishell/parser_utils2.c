/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:43:57 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:49:48 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*strip_quotes_filename(const char *str)
{
	int		len;
	int		i;
	int		j;
	char	*result;

	len = ft_strlen(str);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i++;
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

t_redirect	*create_redirection(int type, char **file)
{
	t_redirect	*new_red;

	new_red = (t_redirect *)malloc(sizeof(t_redirect));
	if (!new_red)
	{
		perror("malloc failed for redirection");
		return (NULL);
	}
	new_red->type = get_redir_type(type);
	new_red->filename = strip_quotes_filename(*file);
	if (!new_red->filename)
	{
		free(new_red);
		perror("malloc failed for redirection file");
		return (NULL);
	}
	new_red->next = NULL;
	return (new_red);
}

void	add_redirection(t_redirect **head, t_redirect *new_redirection)
{
	t_redirect	*current;

	if (!*head)
		*head = new_redirection;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_redirection;
	}
}

int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != TOKEN_PIPE)
	{
		if (tokens->type == TOKEN_WORD)
		{
			if (!tokens->joined_to_prev)
				count++;
		}
		tokens = tokens->next;
	}
	return (count);
}
