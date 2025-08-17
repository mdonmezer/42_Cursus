/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:04:17 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:50:01 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_env_value(t_shell *shell, const char *key)
{
	int	i;
	int	key_len;

	if (!shell->envp || !key)
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], key, key_len) == 0
			&& shell->envp[i][key_len] == '=')
			return (shell->envp[i] + key_len + 1);
		i++;
	}
	return (NULL);
}

static void	update_pwd_variables(t_shell *shell, char *old_pwd)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		update_env_var(shell, "OLDPWD", old_pwd);
		update_env_var(shell, "PWD", new_pwd);
		free(new_pwd);
	}
}

static char	*get_cd_path_two(const char *arg, t_shell *shell)
{
	char	*path;

	if (ft_strncmp(arg, "~", 2) == 0)
	{
		path = get_env_value(shell, "HOME");
		if (!path)
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	}
	else
	{
		path = get_env_value(shell, "OLDPWD");
		if (!path)
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		else
			ft_putendl_fd(path, 1);
	}
	return (path);
}

static char	*get_cd_path(t_command *cmd, t_shell *shell, char *old_pwd)
{
	char	*path;

	if (!cmd->args[1])
	{
		path = get_env_value(shell, "HOME");
		if (!path)
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	}
	else if (ft_strncmp(cmd->args[1], "~", 2) == 0
		|| ft_strncmp(cmd->args[1], "-", 2) == 0)
		path = get_cd_path_two(cmd->args[1], shell);
	else
		path = cmd->args[1];
	if (!path)
	{
		free(old_pwd);
		return (NULL);
	}
	return (path);
}

int	builtin_cd(t_command *cmd, t_shell *shell)
{
	char	*path;
	char	*old_pwd;

	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (1);
	path = get_cd_path(cmd, shell, old_pwd);
	if (!path)
		return (1);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(path);
		free(old_pwd);
		return (1);
	}
	update_pwd_variables(shell, old_pwd);
	free(old_pwd);
	return (0);
}
