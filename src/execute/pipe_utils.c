/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:22:14 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:22:14 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd_simple	*get_last_cmd(t_cmd_simple *cmd)
{
	while (cmd && cmd->next)
		cmd = cmd->next;
	return (cmd);
}

t_pipe_list	*get_last_pipe(t_pipe_list *pipes)
{
	while (pipes && pipes->next)
		pipes = pipes->next;
	return (pipes);
}

void	redir_input_to_pipe(int fd, t_tools *data)
{
	if (dup2(fd, 0) < 0 || close(fd) < 0)
		exit_shell_no_mes(errno, data);
}

void	redir_output_to_pipe(int fd, t_tools *data)
{
	if (dup2(fd, 1) < 0 || close(fd) < 0)
		exit_shell_no_mes(errno, data);
}
