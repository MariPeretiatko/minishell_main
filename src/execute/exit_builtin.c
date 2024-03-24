/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:20:10 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:20:10 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	check_arg_is_num(t_tools *data, t_cmd_simple *list)
{
	int		i;
	char	*str;

	i = 0;
	while (list->args_array[1][i])
	{
		if ((!ft_isdigit(list->args_array[1][i])
			&& (list->args_array[1][0] != '+' && list->args_array[1][0] != '-'))
			|| ((list->args_array[1][0] == '+' || list->args_array[1][0] == '-')
			&& !ft_isdigit(list->args_array[1][1])))
		{
			str = put_str_to_str("exit\nminishell: exit: "
					"%s: numeric argument required\n",
					list->args_array[1], data);
			exit_shell(str, 255, data);
		}
		i++;
	}
}

void	exit_builtin(t_tools *data, t_cmd_simple *list)
{
	if (list->args_array[1])
	{
		check_arg_is_num(data, list);
		if (list->args_array[2])
		{
			ft_putstr_fd("exit\nminishell: exit: too many arguments\n",
				STDERR_FILENO);
			data->exit_code = 1;
			return ;
		}
		exit_shell_no_free("exit\n", ft_atoi(list->args_array[1]), data);
	}
	exit_shell_no_free("exit\n", data->exit_code, data);
}
