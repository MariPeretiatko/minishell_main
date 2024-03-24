/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:02:56 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:12:01 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_builtin(t_lexer *lexer)
{
	if (!ft_strcmp(lexer->word, "echo"))
		return (1);
	else if (!ft_strcmp(lexer->word, "cd"))
		return (2);
	else if (!ft_strcmp(lexer->word, "pwd"))
		return (3);
	else if (!ft_strcmp(lexer->word, "export"))
		return (4);
	else if (!ft_strcmp(lexer->word, "unset"))
		return (5);
	else if (!ft_strcmp(lexer->word, "env"))
		return (6);
	else if (!ft_strcmp(lexer->word, "exit"))
		return (7);
	return (0);
}

int	ft_builtin(t_tools *tool, t_cmd_simple *cmd)
{
	int	builtin_type;

	// int builtin_type = ft_is_builtin(cmd);
	builtin_type = ft_is_builtin(tool->lexer_list);
	if (builtin_type)
	{
		if (builtin_type == 1)
		{
			ft_echo(cmd);
			// printf("I am here echo\n");
		}
		if (builtin_type == 2)
		{
			ft_cd(tool, cmd);
			// printf("I am here cd\n");
		}
		if (builtin_type == 3)
		{
			ft_pwd();
			// printf("I am here pwd\n");
		}
		if (builtin_type == 4)
			print_envp(tool->export_list);
		if (builtin_type == 5)
		{
			ft_unset("cmd");
			// printf("I am here cd\n");
		}
		if (builtin_type == 6)
			print_envp(tool->envp_list);
		if (builtin_type == 7)
		{
			ft_exit(tool, cmd);
			// printf("I am here exit\n");
		}
	}
	return (0);
}
