/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:22:35 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:22:35 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	incr_shell_lvl(t_tools *tool)
{
	t_evnp	*env_shlvl;
	t_evnp	*exp_shlvl;
	int		level;
	char	*str;

	env_shlvl = find_env_node(tool->envp_list, "SHLVL");
	exp_shlvl = find_env_node(tool->export_list, "SHLVL");
	if (env_shlvl)
		level = ft_atoi(env_shlvl->value);
	else
		level = 0;
	if (level > 999)
	{
		str = ft_itoa(level);
		put_to_stderr("minishell: warning: shell level (%s) "
			"too high, resetting to 1\n", str, tool, 0);
		free(str);
	}
	shlvl_helper(tool, env_shlvl, level, tool->envp_list);
	shlvl_helper(tool, exp_shlvl, level, tool->export_list);
}

void	shlvl_high(t_evnp *env_list, int level)
{
	free(env_list->value);
	if (level == 999)
		env_list->value = ft_strdup("");
	else
		env_list->value = ft_strdup("1");
}

void	shlvl_helper(t_tools *data, t_evnp *env_list, int level, t_evnp *head)
{
	char	**shlvl_array;

	if (env_list == NULL)
	{
		shlvl_array = malloc(sizeof(char *) * 2);
		if (!shlvl_array)
			exit_shell_no_mes(1, data);
		shlvl_array[0] = ft_strdup("SHLVL");
		shlvl_array[1] = ft_strdup("1");
		ft_envadd_back(&head, ft_envnew(shlvl_array));
		free(shlvl_array[0]);
		free(shlvl_array[1]);
		free(shlvl_array);
	}
	else if (level >= 999 || ft_strcmp(env_list->value, "") == 0)
		shlvl_high(env_list, level);
	else
	{
		level += 1;
		ft_strdel(&env_list->value);
		env_list->value = ft_itoa(level);
	}
}
