/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:54:12 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:26:53 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_exported_vars(char **envp)
{
	int		i;
	int		equal_pos;
	char	*var_name;
	char	*var_value;

	i = -1;
	while (envp && envp[++i])
	{
		equal_pos = 0;
		while (envp[i][equal_pos] && envp[i][equal_pos] != '=')
			equal_pos++;
		if (envp[i][equal_pos] == '=' && envp[i][equal_pos + 1] != '\0')
		{
			var_name = ft_substr(envp[i], 0, equal_pos);
			var_value = ft_substr(envp[i], equal_pos + 1,
					ft_strlen(envp[i]) - equal_pos - 1);
			printf("export %s=\"%s\"\n", var_name, var_value);
			free(var_name);
			free(var_value);
		}
		else if (envp[i][equal_pos] == '=' && envp[i][equal_pos + 1] == '\0')
			continue ;
		else
			printf("export %s\n", envp[i]);
	}
}

static int	is_valid_export_arg(char *arg)
{
	int	i;

	if (!arg || !arg[0])
		return (0);
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (0);
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	add_to_env(char ***envp, char *arg)
{
	int	var_len;
	int	env_index;
	int	env_size;

	var_len = 0;
	while (arg[var_len] && arg[var_len] != '=')
		var_len++;
	if (arg[var_len] == '=' && arg[var_len + 1] == '\0')
		return (0);
	env_index = find_env_var(*envp, arg, var_len);
	if (env_index >= 0)
		return (update_env_entry(envp, env_index, arg));
	env_size = get_env_size(*envp);
	return (append_env_entry(envp, arg, env_size));
}

static int	process_export_arg(char *arg, char ***envp)
{
	if (!is_valid_export_arg(arg))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	if (add_to_env(envp, arg) != 0)
		return (1);
	return (0);
}

int	builtin_export(t_command *cmd, t_shell *shell)
{
	int	i;
	int	ret_status;

	if (!cmd->args[1])
	{
		print_exported_vars(shell->envp);
		return (0);
	}
	ret_status = 0;
	i = 1;
	while (cmd->args[i])
	{
		if (process_export_arg(cmd->args[i], &shell->envp))
			ret_status = 1;
		i++;
	}
	return (ret_status);
}
