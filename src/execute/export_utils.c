/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:20:35 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:20:35 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_export_exist(t_tools *data)
{
	int i;
	t_evnp *export_list;

	i = 0;
	export_list = data->export_list;
	while (export_list)
	{
		export_list = export_list->next;
		i++;
	}
	return (i);
}

int	check_env_exist(t_tools *data)
{
	int i;
	t_evnp *env_list;

	i = 0;
	env_list = data->envp_list;
	while (env_list)
	{
		env_list = env_list->next;
		i++;
	}
	return (i);
}

void	create_new_export(t_tools *data, char **arg)
{
	data->export_list = ft_envnew(arg);
	if (check_env_exist(data) == 0 && arg[1] && ft_strcmp(arg[1], "") != 0)
		data->envp_list = ft_envnew(arg);
}

void	check_export_null(t_evnp *head_export, t_evnp **env_list,
		t_evnp **export_list, char **arg)
{
	if (*export_list == NULL)
	{
		(*export_list) = head_export;
        ft_lstadd_back_e((export_list), ft_envnew(arg));
		if (arg[1] && ft_strcmp(arg[1], "") != 0)
			ft_envadd_back((env_list), ft_envnew(arg));
	}
}
