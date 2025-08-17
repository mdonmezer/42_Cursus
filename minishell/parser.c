/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 02:03:45 by beergin           #+#    #+#             */
/*   Updated: 2025/08/14 20:43:31 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_heredoc(t_token **token_iter, t_command *new_cmd)
{
	*token_iter = (*token_iter)->next;
	if (!(*token_iter) || (*token_iter)->type != TOKEN_WORD)
	{
		if (*token_iter)
			printf("minishell: syntax error near unexpected token  %s\n",
				(*token_iter)->value);
		else
			printf("minishell: syntax error near unexpected token  %s\n",
				"newline");
		free(new_cmd->args);
		free(new_cmd);
		return (0);
	}
	return (1);
}

int	fill_args(t_token **token_iter, t_command *new_cmd, t_command *cmd_head)
{
	int	i;

	i = 0;
	while (*token_iter && (*token_iter)->type != TOKEN_PIPE)
	{
		if (!handle_token(token_iter, new_cmd, cmd_head, &i))
			return (0);
		*token_iter = (*token_iter)->next;
	}
	new_cmd->args[i] = NULL;
	return (1);
}

t_command	*init_new_command(t_token *cmd_start_token, t_command *cmd_head)
{
	t_command	*new_cmd;
	int			arg_count;

	new_cmd = (t_command *)malloc(sizeof(t_command));
	if (!new_cmd)
	{
		perror("malloc failed for command");
		free_commands(cmd_head);
		return (NULL);
	}
	new_cmd->redirects = NULL;
	new_cmd->next = NULL;
	new_cmd->heredoc_delimiter = NULL;
	arg_count = count_args(cmd_start_token);
	new_cmd->args = (char **)malloc(sizeof(char *) * (arg_count + 1));
	if (!new_cmd->args)
	{
		perror("malloc failed for args");
		free_commands(cmd_head);
		free(new_cmd);
		return (NULL);
	}
	return (new_cmd);
}

t_command	*parser(t_token *tokens, t_shell *shell)
{
	t_command	*cmd_head;
	t_command	*current_cmd;
	t_token		*token_iter;

	cmd_head = NULL;
	current_cmd = NULL;
	token_iter = tokens;
	if (!tokens)
		return (NULL);
	while (token_iter)
	{
		if (!process_command_block(&token_iter, &cmd_head, &current_cmd, shell))
			return (NULL);
		if (token_iter && token_iter->type == TOKEN_PIPE)
		{
			token_iter = token_iter->next;
			if (!handle_pipe_syntax(token_iter, cmd_head))
				return (NULL);
		}
	}
	return (cmd_head);
}
