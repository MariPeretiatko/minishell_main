/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:20:22 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:20:22 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	return_in_out(t_tools *data)
{
	if (data && data->in >= 0 && data->out >= 0)
	{
		if (close(STDOUT_FILENO) < 0 || close(STDIN_FILENO) < 0
			|| dup2(data->in, 0) < 0 || dup2(data->out, 1) < 0
			|| close(data->in) < 0 || close(data->out) < 0)
			exit_shell_no_mes(errno, data);
	}
}

void	redir_input(t_cmd_simple *list, t_tools *data)
{
	int file;

	if (list->fd_in != -1)
		file = list->fd_in;
	else
		file = open(list->in->redir_word->word, O_RDONLY, 0777);
	if (file < 0)
	{
		put_to_stderr_and_exit("minishell> %s: No such file or directory\n",
			list->in->redir_word->word, data, errno);
	}
	else if (dup2(file, STDIN_FILENO) < 0 || close(file) < 0)
		exit_shell_no_mes(errno, data);
}

void	redir_output(t_redir *redir, t_tools *data)
{
	int file;

	file = 0;
	if (redir->redir_token->token == GREATER)
		file = open(redir->redir_word->word, O_WRONLY | O_TRUNC, 0777);
	else if (redir->redir_token->token == GREATER_GREATER)
		file = open(redir->redir_word->word, O_WRONLY | O_APPEND, 0777);
	if (file < 0 || dup2(file, STDOUT_FILENO) < 0 || close(file) < 0)
		exit_shell_no_mes(errno, data);
}

void	redir_input_output(t_cmd_simple *list, t_tools *data)
{
	if (list && (list->in || list->fd_in != -1))
		redir_input(list, data);
	if (list && list->out)
		redir_output(list->out, data);
}
