/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:29:10 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 22:29:10 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_data(t_tools *tool)
{
	if (!tool)
		return ;
	free_2darray(tool->path_cmd);
	// free_2darray(tool->new_env_array);
	free_tokens(&tool->lexer_list);
	ft_envclear(&tool->envp_list);
	ft_envclear(&tool->export_list);
	free_list(&tool->cmd);
	ft_strdel(&tool->input_line);
	free(tool);
	tool = NULL;
}

void	free_tokens(t_lexer **begin)
{
	t_lexer *tmp;
	t_lexer *tmp2;

	if (!begin)
		return ;
	tmp = *begin;
	while (tmp)
	{
		ft_strdel(&tmp->word);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*begin = NULL;
}

void	free_redir_list(t_redir **redir)
{
	t_redir *tmp;

	tmp = NULL;
	if (!(*redir))
		return ;
	while (*redir)
	{
		tmp = (*redir)->next;
		free(*redir);
		*redir = tmp;
	}
}

void	free_list(t_cmd_simple **list)
{
	t_cmd_simple *tmp;

	tmp = NULL;
	if (!(*list))
		return ;
	while ((*list))
	{
		tmp = (*list)->next;
		free_2darray((*list)->args_array);
		if ((*list)->redir_list)
		{
			free_redir_list(&((*list)->redir_list));
			free((*list)->redir_list);
		}
		free((*list));
		(*list) = tmp;
	}
}

void	free_pipe(t_pipe_list *pipes)
{
	t_pipe_list *tmp;

	while (pipes)
	{
		tmp = pipes;
		pipes = pipes->next;
		free(tmp);
	}
}
