/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:01:06 by asitailo          #+#    #+#             */
/*   Updated: 2024/03/16 01:49:34 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"


int	get_size(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (i);
}

int	check_code(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!((int)str[i] > 47 && (int)str[i] < 58))
			return (0);
		i++;
	}
	return (1);
}

int	get_num(char *str)
{
	int	num;

	if (!check_code(str))
		num = 255;
	else
		num = ft_atoi(str);
	return (num);
}

// , t_struct struct
void	ft_exit(t_tools *tool, t_cmd_simple *cmd)
{
	int	size;
	int	code;

	size = get_size(cmd->args_array);
	if (size == 1)
		code = 0;
	else if (size == 2)
		code = get_num(cmd->args_array[1]);
	else
	{
		ft_putstr_fd("Incorrect command parameters", 1);
		return (1);
	}
	printf("i am in exit\n");
	exit(code % 256);
	exit_shell_no_free("exit\n", ft_atoi(cmd->args_array[1]), tool);
	return (0);
}
	// free();
