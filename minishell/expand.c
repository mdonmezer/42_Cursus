/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:16:16 by beergin           #+#    #+#             */
/*   Updated: 2025/08/13 11:56:43 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_expand_result(char **result, char *expanded)
{
	*result = append_str(*result, expanded);
	free(expanded);
}

static void	append_normal_char(char **result, const char *str, int *i)
{
	char	buf[2];

	buf[0] = str[*i];
	buf[1] = '\0';
	*result = append_str(*result, buf);
	(*i)++;
}

static char	*expand_string_loop(const char *str, t_shell *shell)
{
	int		i;
	char	*result;
	char	*expanded;

	i = 0;
	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && (ft_isalpha(str[i + 1])
				|| str[i + 1] == '_' || str[i + 1] == '?'))
		{
			expanded = expand_var(str, &i, shell);
			if (!expanded)
				return (free(result), NULL);
			handle_expand_result(&result, expanded);
			if (!result)
				return (NULL);
		}
		else
			append_normal_char(&result, str, &i);
	}
	return (result);
}

char	*expand_string(char *str, t_shell *shell)
{
	if (!str)
		return (NULL);
	return (expand_string_loop(str, shell));
}

void	expand_variables(t_token *tokens, t_shell *shell)
{
	t_token	*tmp;
	char	*expanded;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == TOKEN_WORD && ft_strchr(tmp->value, '$'))
		{
			if (tmp->quote_type == 1)
			{
				tmp = tmp->next;
				continue ;
			}
			expanded = expand_string(tmp->value, shell);
			if (!expanded)
			{
				perror("expand_variables malloc error");
				exit(1);
			}
			free(tmp->value);
			tmp->value = expanded;
		}
		tmp = tmp->next;
	}
}
