/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:22:23 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:22:23 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


void	manage_delim(t_cmd_simple *list, t_tools *data)
{
	t_redir *redir_list;

	redir_list = list->redir_list;
	while (redir_list)
	{
		if (g_signal == SIGINT)
			break ;
		else if (redir_list->redir_token->token == LESS_LESS)
			delim(redir_list->redir_word->word, data, list);
		redir_list = redir_list->next;
	}
}

int	set_redir_status(t_cmd_simple *list)
{
	list->redir_status = -1;
	return (0);
}

void	exec_first_cmd_in_pipe(t_tools *data, t_cmd_simple *cmd,
		t_pipe_list *first, t_pipe_list *pipes)
{
	int pid;

	if (cmd && cmd->prev)
	{
		if (cmd->redir_status == -1)
			return ;
		pid = fork();
		if (pid < 0)
			exit_shell_no_mes(errno, data);
		if (pid == 0)
		{
			close_fds(&first, pipes, NULL);
			redir_input_to_pipe(pipes->fd[0], data);
			exec_cmd(data, cmd);
			exit_shell_no_mes(errno, data);
		}
	}
}

void	exec_lst_cmd_in_pipe(t_tools *data, t_cmd_simple *list,
		t_pipe_list *first, t_pipe_list *pipes)
{
	int pid;
	int status;

	pid = fork();
	status = 0;
	if (pid < 0)
		exit_shell_no_mes(errno, data);
	if (pid == 0)
	{
		close_fds(&first, NULL, pipes);
		redir_output_to_pipe(pipes->fd[1], data);
		exec_cmd(data, list);
		exit_shell_no_mes(errno, data);
	}
	close_fds(&first, NULL, NULL);
	while (waitpid(pid, &status, 0) > 0)
		continue ;
	free_pipe(pipes);
	data->exit_code = WEXITSTATUS(status);
	return_in_out(data);
}

void	exec_pipe(t_tools *data, t_cmd_simple *list)
{
	t_pipe_list *pipes;
	t_pipe_list *first_pipe;

	first_pipe = create_pipes(list);
	pipes = first_pipe;
	list = get_last_cmd(list);
	pipes = get_last_pipe(pipes);
	exec_first_cmd_in_pipe(data, list, first_pipe, pipes);
	if (list && list->prev)
		list = list->prev;
	while (list && list->prev)
	{
		pipes = pipes->prev;
		if (fork() == 0)
		{
			close_fds(&first_pipe, pipes, pipes->next);
			redir_input_to_pipe(pipes->fd[0], data);
			redir_output_to_pipe(pipes->next->fd[1], data);
			exec_cmd(data, list);
			exit_shell_no_mes(errno, data);
		}
		list = list->prev;
	}
	exec_lst_cmd_in_pipe(data, list, first_pipe, pipes);
}
