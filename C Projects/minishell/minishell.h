/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:56:45 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:48:10 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

# define TOKEN_WORD 1
# define TOKEN_PIPE 2
# define TOKEN_REDIRECT_IN 3
# define TOKEN_REDIRECT_OUT 4
# define TOKEN_REDIRECT_APPEND 5
# define TOKEN_HERE_DOC 6

# define REDIR_IN 0
# define REDIR_OUT 1
# define REDIR_APPEND 2
# define REDIR_HEREDOC 3

typedef struct s_token
{
	char			*value;
	int				type;
	int				quote_type;
	int				joined_to_prev;
	struct s_token	*next;
}t_token;

typedef struct s_redirect
{
	char				*filename;
	int					type;
	int					pipe_fd;
	struct s_redirect	*next;
}						t_redirect;

typedef struct s_command
{
	char				**args;
	t_redirect			*redirects;
	char				*heredoc_delimiter;
	struct s_command	*next;
}						t_command;

typedef struct s_shell
{
	char				**envp;
	int					last_exit_code;
	t_command			*command;
	t_token				*token;
}						t_shell;

typedef struct s_heredoc
{
	int				pipe_fd[2];
	pid_t			pid;
	int				expand;
	char			*line;
	int				status;
	t_redirect		*heredoc_redir;
}t_heredoc;

typedef struct s_error_msg
{
	const char	*subject;
	const char	*suffix;
}t_error_msg;

typedef struct s_parent_ctx
{
	struct s_command	*command;
	struct s_shell		*shell;
	int					*in_fd;
	int					(*pipe_fd)[2];
	pid_t				pid;
}t_parent_ctx;

t_token					*lexer(char *line);
int						is_whitespace(char c);
int						is_metachar(char c);
t_token					*create_token(char *value, int type, int quote_type);
void					add_token(t_token **head, t_token *new_token);
void					free_tokens(t_token *head);
void					free_envp(char **envp);
void					execute_pipeline(t_command *pipeline, t_shell *shell);
t_redirect				*create_redirection(int type, char **file);
void					add_redirection(t_redirect **head,
							t_redirect *new_redirection);
void					free_redirections(t_redirect *head);
void					free_commands(t_command *head);
int						count_args(t_token *tokens);
char					*get_command_path(char *cmd, t_shell *shell);
void					print_error_s(t_error_msg e);
void					free_path(char **path);
char					*direct_path(char *c);
char					*find_path_line(t_shell *sh);
char					*search_in_paths(char **p, char *c);
t_command				*parser(t_token *tokens, t_shell *shell);
int						builtin_pwd(void);
int						is_builtin(char *cmd);
int						builtin_env(t_shell *shell);
void					handle_signal(int signo);
int						builtin_cd(t_command *cmd, t_shell *shell);
int						execute_builtin(t_command *cmd, t_shell *shell);
int						handle_redirections(t_command *cmd);
int						builtin_exit(t_command *cmd, t_shell *shell);
int						builtin_echo(t_command *cmd);
int						builtin_unset(t_command *cmd, t_shell *shell);
int						builtin_export(t_command *cmd, t_shell *shell);
int						create_and_replace_env(t_shell *shell,
							const char *key, const char *value, int i);
int						update_env_var(t_shell *shell, const char *key,
							const char *value);
void					run_child_path(t_command *p, t_shell *sh);
void					handle_parent(t_parent_ctx ctx);
void					finalize_pipeline(pid_t last_pid, t_shell *shell);
int						is_single_builtin(t_command *p);
int						find_env_var(char **envp, char *var_name, int var_len);
int						get_env_size(char **envp);
char					**create_new_env(char **old_envp, int size);
int						update_env_entry(char ***envp, int env_index,
							char *arg);
int						append_env_entry(char ***envp, char *arg,
							int env_size);
char					**copy_envp(char **envp);
void					expand_variables(t_token *tokens, t_shell *shell);
void					parse_heredoc(t_command *cmd, t_token *token,
							t_shell *shell);
int						execute_heredoc(t_command *cmd, t_shell *shell);
int						heredoc_parent(t_command *cmd, t_heredoc *hd);
int						is_expandable_delim(int quote_type);
char					*expand_string(char *str, t_shell *shell);
char					*expand_variables2(char *line, t_shell *shell);
char					*get_var_value(char *var_name, int is_special_var,
							t_shell *shell);
int						get_var_name(const char *str, int *i, char **var_name);
char					*append_str(char *dest, const char *src);
char					*get_env_value_e(char *var_name, t_shell *shell);
char					*expand_var(const char *str, int *i, t_shell *shell);
int						handle_pipe(int i, t_token **tokens);
int						handle_redirect(char *line, int i, t_token **tokens);
int						handle_single_quote(char *line, int i,
							t_token **tokens);
int						handle_word(char *line, int i, t_token **tokens);
int						handle_double_quote(char *line, int i,
							t_token **tokens);
int						lexer_handle_token(char *line, int i,
							t_token **tokens);
int						lexer_handle_quotes(char *line, int i,
							t_token **tokens);
void					write_heredoc_line(int fd, char *line, int expand,
							t_shell *shell);
int						get_redir_type(int type);
void					print_syntx_err(t_token **token_iter);
int						handle_redirects(t_token **token_iter,
							t_command *new_cmd, t_command *cmd_head);
int						handle_heredoc(t_token **token_iter,
							t_command *new_cmd);
int						handle_token(t_token **token_iter,
							t_command *new_cmd, t_command *cmd_head, int *i);
int						handle_exit_command(char *line, t_shell *shell);
void					setup_redirections(int in_fd, int pipe_fd[2],
							t_command *p);
t_command				*init_new_command(t_token *cmd_start_token,
							t_command *cmd_head);
int						handle_pipe_syntax(t_token *token_iter,
							t_command *cmd_head);
int						process_command_block(t_token **token_iter,
							t_command **cmd_head,
							t_command **current_cmd, t_shell *shell);
int						fill_args(t_token **token_iter, t_command *new_cmd,
							t_command *cmd_head);
void					free_shell_all(t_shell *shell);
void					cleanup_and_exit(t_shell *shell, int status);
#endif
