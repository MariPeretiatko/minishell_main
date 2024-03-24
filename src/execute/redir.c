/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:22:30 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:22:30 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	output(t_redir *redir, t_tools *data, t_cmd_simple *list)
{
	int file;

	file = open(redir->redir_word->word, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	list->out = redir;
	if (file < 0)
		exit_shell_no_mes(errno, data);
	if (close(file) < 0)
		exit_shell_no_mes(errno, data);
}

int	input(t_redir *redir, t_tools *data, t_cmd_simple *list, int delim)
{
	int file;

	file = open(redir->redir_word->word, O_RDONLY, 0777);
	if (file < 0)
	{
		put_to_stderr("minishell: %s: No such file or directory\n",
			redir->redir_word->word, data, errno);
		return (0);
	}
	else
	{
		list->in = redir;
		if (delim == 1)
			list->fd_in = -1;
		if (close(file) < 0)
			exit_shell_no_mes(errno, data);
	}
	return (1);
}

void	append(t_redir *redir, t_tools *data, t_cmd_simple *list)
{
	int file;

	file = open(redir->redir_word->word, O_WRONLY | O_CREAT | O_APPEND, 0777);
	list->out = redir;
	if (file < 0 || close(file) < 0)
		exit_shell_no_mes(errno, data);
}

void	delim(char *name, t_tools *data, t_cmd_simple *list)
{
	int pid;
	int fd[2];
	int status;

	if (pipe(fd) < 0)
		exit_shell_no_mes(errno, data);
	if (list->fd_in != -1 && close(list->fd_in) < 0)
		exit_shell_no_mes(errno, data);
	status = 0;
	pid = fork();
	if (pid < 0)
		exit_shell_no_mes(errno, data);
	if (pid == 0)
		read_input_delim(name, data->in, data->out, fd[1]);
	waitpid(pid, &status, 0);
	data->exit_code = WEXITSTATUS(status);
	list->fd_in = fd[0];
	if (close(fd[1]) < 0)
		exit_shell_no_mes(errno, data);
}

int	manage_redir(t_cmd_simple *list, t_tools *data)
{
	t_redir *redir_list;
	int del;

	del = 0;
	redir_list = list->redir_list;
	manage_delim(list, data);
	while (redir_list)
	{
		if (g_signal == SIGINT)
			break ;
		if (redir_list->redir_token->token == GREATER)
			output(redir_list, data, list);
		else if (redir_list->redir_token->token == LESS)
		{
			if (input(redir_list, data, list, del) == 0)
				return (set_redir_status(list));
			del = 0;
		}
		else if (redir_list->redir_token->token == GREATER_GREATER)
			append(redir_list, data, list);
		else if (redir_list->redir_token->token == LESS_LESS)
			del = 1;
		redir_list = redir_list->next;
	}
	return (1);
}
