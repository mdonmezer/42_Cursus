/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:30:07 by beergin           #+#    #+#             */
/*   Updated: 2025/08/14 20:41:57 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir_type(int type)
{
	if (type == TOKEN_REDIRECT_IN)
		return (REDIR_IN);
	else if (type == TOKEN_REDIRECT_OUT)
		return (REDIR_OUT);
	else if (type == TOKEN_REDIRECT_APPEND)
		return (REDIR_APPEND);
	else if (type == TOKEN_HERE_DOC)
		return (REDIR_HEREDOC);
	return (REDIR_IN);
}

void	print_syntx_err(t_token **token_iter)
{
	if (*token_iter)
		printf("minishell: syntax error near unexpected token  %s\n",
			(*token_iter)->value);
	else
		printf("minishell: syntax error near unexpected token  %s\n",
			"newline");
}

int	handle_pipe_syntax(t_token *token_iter, t_command *cmd_head)
{
	if (!token_iter && cmd_head)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		free_commands(cmd_head);
		return (0);
	}
	return (1);
}

int	process_command_block(t_token **token_iter, t_command **cmd_head,
		t_command **current_cmd, t_shell *shell)
{
	t_command	*new_cmd;
	t_token		*cmd_start_token;

	cmd_start_token = *token_iter;
	new_cmd = init_new_command(cmd_start_token, *cmd_head);
	if (!new_cmd)
		return (0);
	if (!fill_args(token_iter, new_cmd, *cmd_head))
		return (0);
	parse_heredoc(new_cmd, cmd_start_token, shell);
	if (!*cmd_head)
		*cmd_head = new_cmd;
	else
		(*current_cmd)->next = new_cmd;
	*current_cmd = new_cmd;
	return (1);
}
