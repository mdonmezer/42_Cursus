/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:29:53 by beergin           #+#    #+#             */
/*   Updated: 2025/08/15 20:24:17 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_shell(t_shell *shell, char **envp)
{
	shell->envp = copy_envp(envp);
	if (!shell->envp)
	{
		ft_putstr_fd("Failed to copy environment\n", 2);
		return (1);
	}
	shell->last_exit_code = 0;
	shell->command = NULL;
	shell->token = NULL;
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

static void	free_shell_fields(t_shell *shell)
{
	if (shell->token)
	{
		free_tokens(shell->token);
		shell->token = NULL;
	}
	if (shell->command)
	{
		free_commands(shell->command);
		shell->command = NULL;
	}
}

static int	process_input_line(char *line, t_shell *shell)
{
	add_history(line);
	if (ft_strncmp(line, "exit", 4) == 0
		&& (line[4] == '\0' || line[4] == ' '))
		return (handle_exit_command(line, shell));
	shell->token = lexer(line);
	if (shell->token)
	{
		expand_variables(shell->token, shell);
		shell->command = parser(shell->token, shell);
		if (shell->command)
			execute_pipeline(shell->command, shell);
	}
	return (0);
}

static void	repl_loop(t_shell *shell)
{
	char	*line;

	while (1)
	{
		free_shell_fields(shell);
		line = readline("$> ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (line[0] != '\0' && process_input_line(line, shell))
		{
			free(line);
			break ;
		}
		free(line);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	if (init_shell(&shell, envp))
		return (1);
	repl_loop(&shell);
	free_shell_fields(&shell);
	free_envp(shell.envp);
	return (shell.last_exit_code);
}
