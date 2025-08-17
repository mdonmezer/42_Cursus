/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:50:37 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:26:39 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*strip_quotes(const char *str)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	if (len >= 2 && ((str[0] == '"' && str[len - 1] == '"')
			|| (str[0] == '\'' && str[len - 1] == '\'')))
	{
		result = ft_substr(str, 1, len - 2);
		return (result);
	}
	return (ft_strdup(str));
}

static int	is_numeric(const char *str)
{
	int		i;
	char	*clean_str;
	int		result;

	clean_str = strip_quotes(str);
	if (!clean_str)
		return (0);
	i = 0;
	if (clean_str[i] == '+' || clean_str[i] == '-')
		i++;
	if (clean_str[i] == '\0')
	{
		free(clean_str);
		return (0);
	}
	while (clean_str[i])
	{
		if (!ft_isdigit(clean_str[i]))
			return (free(clean_str), 0);
		i++;
	}
	result = 1;
	free(clean_str);
	return (result);
}

static int	parse_exit_code(const char *str)
{
	char	*clean_str;
	int		exit_code;

	clean_str = strip_quotes(str);
	if (!clean_str)
		return (0);
	exit_code = ft_atoi(clean_str);
	free(clean_str);
	return (exit_code);
}

int	builtin_exit(t_command *cmd, t_shell *shell)
{
	int		exit_code;

	ft_putendl_fd("exit", 1);
	if (!cmd->args[1])
		return (shell->last_exit_code);
	if (!is_numeric(cmd->args[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		return (2);
	}
	if (cmd->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	exit_code = parse_exit_code(cmd->args[1]);
	return (exit_code);
}
