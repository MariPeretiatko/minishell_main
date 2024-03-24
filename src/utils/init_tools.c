/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:09:17 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:11:11 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_tools(t_tools **tools, char *envp[])
{
	*tools = malloc(sizeof(t_tools));
	if (!*tools)
		exit(EXIT_FAILURE);
	(*tools)->minishell = "minishell> ";
	(*tools)->input_line = NULL;
	(*tools)->in = -1;
	(*tools)->out = -1;
	(*tools)->cmd = NULL;
	(*tools)->exit_code = 0;
	(*tools)->lexer_list = NULL;
	(*tools)->path_cmd = NULL;
	if (*envp == NULL)
		envp = create_envp();
	(*tools)->envp_list = init_envp(envp);
	(*tools)->export_list = init_envp(envp);
}
// printenvp((*tools)->envp_list);
