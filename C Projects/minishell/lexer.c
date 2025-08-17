/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:43:44 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/13 12:25:19 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer_handle_token(char *line, int i, t_token **tokens);

int	handle_redirect(char *line, int i, t_token **tokens)
{
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
		{
			add_token(tokens, create_token(ft_strdup("<<"), TOKEN_HERE_DOC, 0));
			return (i + 2);
		}
		add_token(tokens, create_token(ft_strdup("<"), TOKEN_REDIRECT_IN, 0));
		return (i + 1);
	}
	if (line[i] == '>')
	{
		if (line[i + 1] == '>')
		{
			add_token(tokens, create_token(ft_strdup(">>"),
					TOKEN_REDIRECT_APPEND, 0));
			return (i + 2);
		}
		add_token(tokens, create_token(ft_strdup(">"), TOKEN_REDIRECT_OUT, 0));
		return (i + 1);
	}
	return (i);
}

int	handle_single_quote(char *line, int i, t_token **tokens)
{
	int		start;
	int		joined;
	t_token	*tok;

	i++;
	start = i;
	while (line[i] && line[i] != '\'')
		i++;
	if (line[i] == '\'')
	{
		joined = 0;
		if (start > 1 && !is_whitespace(line[start - 2])
			&& !is_metachar(line[start - 2]))
			joined = 1;
		tok = create_token(ft_substr(line, start, i - start), TOKEN_WORD, 1);
		if (tok)
			tok->joined_to_prev = joined;
		add_token(tokens, tok);
		return (i + 1);
	}
	printf("minishell: unclosed quote\n");
	free_tokens(*tokens);
	return (-1);
}

int	handle_double_quote(char *line, int i, t_token **tokens)
{
	int		start;
	int		joined;
	t_token	*tok;

	i++;
	start = i;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"')
	{
		joined = 0;
		if (start > 1 && !is_whitespace(line[start - 2])
			&& !is_metachar(line[start - 2]))
			joined = 1;
		tok = create_token(ft_substr(line, start, i - start), TOKEN_WORD, 2);
		if (tok)
			tok->joined_to_prev = joined;
		add_token(tokens, tok);
		return (i + 1);
	}
	printf("minishell: unclosed quote\n");
	free_tokens(*tokens);
	return (-1);
}

int	handle_word(char *line, int i, t_token **tokens)
{
	int		start;
	int		joined;
	t_token	*tok;

	start = i;
	while (line[i] && !is_whitespace(line[i]) && !is_metachar(line[i])
		&& line[i] != '\'' && line[i] != '"')
		i++;
	joined = 0;
	if (start > 0 && !is_whitespace(line[start - 1])
		&& !is_metachar(line[start - 1]))
		joined = 1;
	tok = create_token(ft_substr(line, start, i - start),
			TOKEN_WORD, 0);
	if (tok)
		tok->joined_to_prev = joined;
	add_token(tokens, tok);
	return (i);
}

t_token	*lexer(char *line)
{
	t_token	*tokens;
	int		i;
	int		ret;

	i = 0;
	tokens = NULL;
	if (!line)
		return (NULL);
	while (line[i])
	{
		while (line[i] && is_whitespace(line[i]))
			i++;
		if (!line[i])
			break ;
		ret = lexer_handle_token(line, i, &tokens);
		if (ret == -1)
			return (NULL);
		i = ret;
	}
	return (tokens);
}
