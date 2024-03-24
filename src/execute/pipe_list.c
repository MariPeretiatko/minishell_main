/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:22:09 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:22:09 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_pipes(t_cmd_simple *list)
{
	int				pipes;
	t_cmd_simple	*copy;

	copy = list;
	pipes = 0;
	while (copy && copy->next)
	{
		copy = copy->next;
		pipes++;
	}
	return (pipes);
}

t_pipe_list	*create_pipe(t_pipe_list *current)
{
	t_pipe_list	*new_pipe;

	new_pipe = malloc(sizeof(t_pipe_list));
	new_pipe->next = NULL;
	new_pipe->prev = current;
	return (new_pipe);
}

t_pipe_list	*create_pipes(t_cmd_simple *list)
{
	int				pipe_num;
	t_pipe_list		*pipe_list;
	t_pipe_list		*first_pipe;
	t_pipe_list		*new_pipe;

	pipe_num = count_pipes(list);
	first_pipe = NULL;
	while (pipe_num > 0)
	{
		if (!first_pipe)
		{
			first_pipe = create_pipe(NULL);
			pipe_list = first_pipe;
		}
		else
		{
			new_pipe = create_pipe(pipe_list);
			pipe_list->next = new_pipe;
			pipe_list = pipe_list->next;
		}
		pipe(pipe_list->fd);
		pipe_num--;
	}
	return (first_pipe);
}

void	close_fds(t_pipe_list **first_pipe, t_pipe_list *in, t_pipe_list *out)
{
	t_pipe_list	*copy;

	copy = *first_pipe;
	while (copy)
	{
		if (in && copy == in)
			close(copy->fd[1]);
		else if (out && copy == out)
			close(copy->fd[0]);
		else
		{
			close(copy->fd[1]);
			close(copy->fd[0]);
		}
		copy = copy->next;
	}
}
