/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:33:00 by beergin           #+#    #+#             */
/*   Updated: 2025/08/13 12:01:34 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_str(char *dest, const char *src)
{
	size_t	len_dest;
	size_t	len_src;
	char	*new_str;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	new_str = malloc(len_dest + len_src + 1);
	if (!new_str)
	{
		free(dest);
		return (NULL);
	}
	ft_memcpy(new_str, dest, len_dest);
	ft_memcpy(new_str + len_dest, src, len_src);
	new_str[len_dest + len_src] = '\0';
	free(dest);
	return (new_str);
}

int	get_var_name(const char *str, int *i, char **var_name)
{
	int	start;

	(*i)++;
	start = *i;
	if (str[*i] == '?')
	{
		(*i)++;
		*var_name = ft_substr(str, start, 1);
		return (1);
	}
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	*var_name = ft_substr(str, start, *i - start);
	return (0);
}

char	*get_var_value(char *var_name, int is_special_var, t_shell *shell)
{
	char	*env_value;
	char	*tmp;

	env_value = get_env_value_e(var_name, shell);
	free(var_name);
	if (is_special_var)
	{
		tmp = ft_strdup(env_value);
		free(env_value);
		return (tmp);
	}
	return (ft_strdup(env_value));
}

char	*expand_var(const char *str, int *i, t_shell *shell)
{
	char	*var_name;
	int		is_special_var;

	is_special_var = get_var_name(str, i, &var_name);
	if (!var_name)
		return (NULL);
	return (get_var_value(var_name, is_special_var, shell));
}

char	*get_env_value_e(char *var_name, t_shell *shell)
{
	int		i;
	size_t	len;
	char	*exit_code_str;

	if (ft_strncmp(var_name, "?", 1) == 0 && ft_strlen(var_name) == 1)
	{
		exit_code_str = ft_itoa(shell->last_exit_code);
		return (exit_code_str);
	}
	i = 0;
	len = ft_strlen(var_name);
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], var_name, len) == 0
			&& shell->envp[i][len] == '=')
			return (shell->envp[i] + len + 1);
		i++;
	}
	return ("");
}
