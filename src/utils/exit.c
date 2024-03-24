/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:37:17 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:37:17 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exit_shell(char *message, int exit_code, t_tools *tool)
{
	return_in_out(tool);
	ft_putstr_fd(message, STDERR_FILENO);
	free(message);
	free_data(tool);
	exit(exit_code);
}

void	exit_shell_no_free(char *message, int exit_code, t_tools *tool)
{
	return_in_out(tool);
	ft_putstr_fd(message, STDERR_FILENO);
	free_data(tool);
	exit(exit_code);
}

void	exit_shell_no_mes(int exit_code, t_tools *tool)
{
	return_in_out(tool);
	free_data(tool);
	exit(exit_code);
}
