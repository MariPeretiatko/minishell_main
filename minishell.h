/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:40:23 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/08 18:15:56 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "inc/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

typedef enum e_token_type
{
	WORD = 0,
	PIPE,
	LESS,
	LESS_LESS,
	GREATER,
	GREATER_GREATER
}						t_token_type;

typedef struct s_lexer
{
	int					index;
	char				*word;
	t_token_type		token;
	struct s_lexer		*prev;
	struct s_lexer		*next;

}						t_lexer;

typedef struct s_evnp
{
	char				*name;
	char				*value;
	struct s_evnp		*next;
	struct s_evnp		*prev;
}						t_evnp;

typedef struct s_redir
{
	t_lexer				*redir_token;
	t_lexer				*redir_word;
	struct s_redir		*next;
}						t_redir;

typedef struct s_cmd_simple
{
	char				*value;
	char				**args_array;
	t_redir				*redir_list;
	t_redir				*in;
	t_redir				*out;
	int					fd_in;
	int					redir_status;
	struct s_cmd_simple	*next;
	struct s_cmd_simple	*prev;
}						t_cmd_simple;

typedef struct s_pipe_list
{
	int					fd[2];
	struct s_pipe_list	*next;
	struct s_pipe_list	*prev;
}						t_pipe_list;

typedef struct s_tools
{
	t_lexer				*lexer_list;
	t_cmd_simple		*cmd;
	t_evnp				*envp_list;
	t_evnp				*export_list;
	char				*minishell;
	char				*input_line;
	char				**path_cmd;
	int					exit_code;
	int					in;
	int					out;
}						t_tools;

int						g_signal;

char					**ft_split(char const *s, char c);
// int						ft_unset(char *argv);
int						ft_pwd(void);
// void					ft_exit(char **argv);
// int						ft_echo(char **argv);
int						ft_strcmp(char *str1, char *str2);

// LEXER
void					print_lexer(t_lexer **lexer);
int						check_token(char *token);
t_lexer					*add_info_lexer(t_lexer **lexer, char **array_str);
t_lexer					*init_lexer(char *str);
t_lexer					*ft_lstlast(t_lexer *lst);
void					ft_lstadd_back(t_lexer **lst, t_lexer *new_list);
t_lexer					*ft_lstnew(int index, char *word);
int						ft_lstsize(t_lexer *lst);
void					remove_lexer_list(t_lexer *head);

// ENVP
void					print_envp_(char **envp);
void					print_envp(t_evnp *array);
char					**init_names(char **envp_array);
char					**init_values(char **envp_array);
t_evnp					*add_info_envp(t_evnp *envp_s, char **name,
							char **value);
t_evnp					*init_envp(char **envp_array);
char					**create_envp(void);
t_evnp					*ft_lstlast_e(t_evnp *lst);
void					ft_lstadd_back_e(t_evnp **lst, t_evnp *new);
t_evnp					*ft_lstnew_e(char *name, char *value);

// TOOLS
void					init_tools(t_tools **tools, char *envp[]);
void					init_path(t_tools *tools);

// BUILTIN
int						ft_is_builtin(t_lexer *lexer);
int						ft_builtin(t_tools *tool, t_cmd_simple *cmd);

// CMD
void					remove_cmd_list(t_cmd_simple *head);
void					init_cmd_simple(t_cmd_simple **cmd);

// FREE
void					delete_tools(t_tools *tools);
void					free_tools(t_tools *tool);

// execve
int						ft_builtin(t_tools *tool, t_cmd_simple *cmd);

void					return_in_out(t_tools *data);
void					redir_input(t_cmd_simple *list, t_tools *data);
void					redir_output(t_redir *redir, t_tools *data);

void					free_data(t_tools *data);
void					free_2darray(char **array);
void					ft_envclear(t_evnp **env_list);
void					free_envir(t_evnp *envir);
void					free_tokens(t_lexer **begin);
void					free_list(t_cmd_simple **list);

void					exit_shell(char *message, int exit_code, t_tools *tool);
void					exit_shell_no_free(char *message, int exit_code,
							t_tools *tool);
void					exit_shell_no_mes(int exit_code, t_tools *tool);

char					*update_input(char *input);
void					process_input(char *input, char *str, int *i, int *j);
int						is_chr_str(char c, char *str);
char					*ft_strstr(const char *haystack, const char *needle);
void					read_input_delim(char *name, int stdin, int stdout,
							int fd);

void					handle_c(int signo);
int						handle_d(t_tools *tool, char *line);
void					handle_sig_child(int signo);
int						in_quotes(char *s, int pos);

// signal
void					handle_signal(void);
void					handle_c(int signo);
int						handle_d(t_tools *tool, char *line);
void					handle_sig_child(int signo);

char					*find_command_path(t_tools *tools, t_cmd_simple *cmd);
char					*find_executable_path(char **paths, char *cmd);
char					*find_env_var(t_tools *tools, char *var_name);

int						odd_quote(char *str);
int						in_quotes(char *s, int pos);
int						in_single_quotes(char *s, int pos);
int						special_chars(char *str);

void					add_str_part(char *str, int i, int start,
							char **result);
void					join_result_with_exit(int exit_status, char **result);
void					replace_variable(t_tools *tools, int *i, int *start,
							char **result);
char					*replace_dollars(t_tools *tools, char *str);
void					fix_quotes(t_tools *tools);

#endif
