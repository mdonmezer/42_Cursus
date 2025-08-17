/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:11:04 by beergin           #+#    #+#             */
/*   Updated: 2025/08/13 12:28:49 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	merge_joined_words(t_token **token_iter, char **merged,
		t_command *new_cmd, t_command *cmd_head)
{
	t_token	*cur;
	char	*tmp;

	cur = *token_iter;
	while (cur->next && cur->next->type == TOKEN_WORD
		&& cur->next->joined_to_prev)
	{
		tmp = *merged;
		*merged = ft_strjoin(*merged, cur->next->value);
		free(tmp);
		if (!*merged)
		{
			free_commands(cmd_head);
			free(new_cmd->args);
			free(new_cmd);
			return (0);
		}
		cur = cur->next;
	}
	*token_iter = cur;
	return (1);
}

static int	validate_redirect_token(t_token **token_iter, t_command *new_cmd)
{
	if (!(*token_iter) || (*token_iter)->type != TOKEN_WORD)
	{
		print_syntx_err(token_iter);
		free(new_cmd->args);
		free(new_cmd);
		return (0);
	}
	return (1);
}

static int	create_and_add_redirection(t_redirect **new_red, int redirect_type,
		char **merged)
{
	*new_red = create_redirection(redirect_type, merged);
	if (!*new_red)
		return (0);
	return (1);
}

static int	handle_redirects_core(t_token **token_iter, t_command *new_cmd,
		t_command *cmd_head)
{
	t_redirect	*new_red;
	int			redirect_type;
	char		*merged;
	t_token		*cur;

	redirect_type = (*token_iter)->type;
	*token_iter = (*token_iter)->next;
	if (!validate_redirect_token(token_iter, new_cmd))
		return (0);
	cur = *token_iter;
	merged = ft_strdup(cur->value);
	if (!merged)
	{
		free_commands(cmd_head);
		free(new_cmd->args);
		free(new_cmd);
		return (0);
	}
	if (!merge_joined_words(&cur, &merged, new_cmd, cmd_head))
		return (0);
	if (!create_and_add_redirection(&new_red, redirect_type, &merged))
		return (0);
	add_redirection(&(new_cmd->redirects), new_red);
	*token_iter = cur;
	return (1);
}

int	handle_redirects(t_token **token_iter, t_command *new_cmd,
		t_command *cmd_head)
{
	return (handle_redirects_core(token_iter, new_cmd, cmd_head));
}
