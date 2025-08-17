/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:02:27 by beergin           #+#    #+#             */
/*   Updated: 2025/08/13 12:26:01 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_pipe(int i, t_token **tokens)
{
	add_token(tokens, create_token(ft_strdup("|"), TOKEN_PIPE, 0));
	return (i + 1);
}

int	lexer_handle_quotes(char *line, int i, t_token **tokens)
{
	int	ret;

	if (line[i] == '\'')
	{
		ret = handle_single_quote(line, i, tokens);
		if (ret == -1)
			return (-1);
		return (ret);
	}
	if (line[i] == '"')
	{
		ret = handle_double_quote(line, i, tokens);
		if (ret == -1)
			return (-1);
		return (ret);
	}
	return (i);
}

int	lexer_handle_token(char *line, int i, t_token **tokens)
{
	if (line[i] == '|')
		return (handle_pipe(i, tokens));
	else if (line[i] == '<' || line[i] == '>')
		return (handle_redirect(line, i, tokens));
	else if (line[i] == '\'' || line[i] == '"')
		return (lexer_handle_quotes(line, i, tokens));
	else
		return (handle_word(line, i, tokens));
}
