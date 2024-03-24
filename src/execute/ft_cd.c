/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:56:50 by asitailo          #+#    #+#             */
/*   Updated: 2024/03/24 21:16:09 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	set_pwd(void)
// {
// 	//
// }

int	get_variable(char **envp, char *var, int var_size)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], var, var_size))
			if (envp[i] && envp[i][var_size] == '=')
				return (i);
		i++;
	}
	return (-1);
}

char	*get_path(char **argv)
{
	char	*path;
	int		i;

	i = 0;
	if (!argv[1])
	{
		i = get_variable(env, "HOME", 4); //
		if (i == -1)
		{
			ft_putstr_fd("cd: HOME not set", 2);
			return (NULL);
		}
		path = env[i] + 5;
	}
	else
		path = argv[1];
	return (path);
}

void	ft_cd(char **argv)
{
	char	*path;

	if (get_env_size(argv) > 2)
	{
		ft_putstr_fd("cd: string not in pwd\n", 2);
		return (1);
	}
	else
	{
		path = get_path(argv);
		if (!path)
			return (-1);
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: no such file or directory\n", 2);
		return (1);
	}
	ft_pwd();
	return (0);
}
// set_pwd();
