/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:29:50 by mperetia          #+#    #+#             */
/*   Updated: 2024/02/23 18:38:32 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void init_cmd_simple(t_cmd_simple **cmd)
{
	*cmd = malloc(sizeof(t_cmd_simple));
	if (!*cmd)
		exit(EXIT_FAILURE);
	(*cmd)->value = NULL;
	(*cmd)->args_array = NULL;
	(*cmd)->redir_list = NULL;
	(*cmd)->in = NULL;
	(*cmd)->out = NULL;
	(*cmd)->fd_in = 0;
	(*cmd)->next = NULL;
	(*cmd)->prev = NULL;
}
