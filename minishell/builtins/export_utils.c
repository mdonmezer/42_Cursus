/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:00:00 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:26:48 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_env_var(char **envp, char *var_name, int var_len)
{
	int	i;

	if (!envp || !var_name)
		return (-1);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_name, var_len) == 0
			&& envp[i][var_len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	get_env_size(char **envp)
{
	int	count;

	count = 0;
	while (envp && envp[count])
		count++;
	return (count);
}

char	**create_new_env(char **old_envp, int size)
{
	char	**new_envp;
	int		i;

	new_envp = malloc(sizeof(char *) * (size + 2));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_envp[i] = old_envp[i];
		i++;
	}
	return (new_envp);
}

int	update_env_entry(char ***envp, int env_index, char *arg)
{
	free((*envp)[env_index]);
	(*envp)[env_index] = ft_strdup(arg);
	if (!(*envp)[env_index])
		return (1);
	return (0);
}

int	append_env_entry(char ***envp, char *arg, int env_size)
{
	char	**new_envp;

	new_envp = create_new_env(*envp, env_size);
	if (!new_envp)
		return (1);
	new_envp[env_size] = ft_strdup(arg);
	new_envp[env_size + 1] = NULL;
	free(*envp);
	*envp = new_envp;
	if (!new_envp[env_size])
		return (1);
	return (0);
}
