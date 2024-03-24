/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:09:17 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/16 02:08:32 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_path(t_tools *tools)
{
	t_evnp	*tmp;
	char	*tmp_str;

	tmp = tools->envp_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PATH"))
		{
			// printf("%s\n", tmp->value);
			tmp_str = tmp->value;
			break ;
		}
		tmp = tmp->next;
	}
	if(tmp)
		tools->path_cmd = ft_split(tmp_str, ':');
	for(int i = 0; tools->path_cmd[i] != NULL; i++)
	{
		printf("%s\n", tools->path_cmd[i]);
	}
}

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
	// printenvp((*tools)->envp_list);
}
