/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:00:00 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:26:07 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	create_and_replace_env(t_shell *shell, const char *key,
					const char *value, int i)
{
	char	*new_var;
	char	*temp;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (1);
	new_var = ft_strjoin(temp, value);
	free(temp);
	if (!new_var)
		return (1);
	free(shell->envp[i]);
	shell->envp[i] = new_var;
	return (0);
}

int	update_env_var(t_shell *shell, const char *key, const char *value)
{
	int		i;
	int		key_len;

	if (!key || !value)
		return (1);
	key_len = ft_strlen(key);
	i = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], key, key_len) == 0
			&& shell->envp[i][key_len] == '=')
			return (create_and_replace_env(shell, key, value, i));
		i++;
	}
	return (1);
}
