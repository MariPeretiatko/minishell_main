/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:56:11 by mperetia          #+#    #+#             */
/*   Updated: 2024/02/26 16:41:12 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**init_names(char **envp_array)
{
	char	**array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (envp_array[i])
		i++;
	array = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp_array[i])
	{
		j = 0;
		while (envp_array[i][j])
		{
			if (envp_array[i][j] == '=')
			{
				array[i] = malloc(sizeof(char) * (j + 1));
				array[i][j] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (envp_array[i])
	{
		j = 0;
		while (envp_array[i][j])
		{
			if (envp_array[i][j] == '=')
				break ;
			array[i][j] = envp_array[i][j];
			j++;
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**init_values(char **envp_array)
{
	char	**array;
	size_t	i;
	size_t	j;
	size_t	size_new;

	size_new = 0;
	i = 0;
	while (envp_array[i])
		i++;
	array = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp_array[i])
	{
		j = ft_strchr(envp_array[i], '=') + 1;
		size_new = 0;
		while (envp_array[i][j])
		{
			size_new++;
			j++;
		}
		array[i] = malloc(sizeof(char) * (size_new + 1));
		array[i][size_new] = '\0';
		i++;
	}
	i = 0;
	j = 0;
	while (envp_array[i])
	{
		j = ft_strchr(envp_array[i], '=') + 1;
		size_new = 0;
		while (envp_array[i][j])
		{
			array[i][size_new] = envp_array[i][j];
			size_new++;
			j++;
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

t_evnp	*add_info_envp(t_evnp *envp_s, char **name, char **value)
{
	int	index;

	index = 0;
	if (!envp_s)
		envp_s = ft_lstnew_e(name[index], value[index]);
	while (name[++index])
		ft_lstadd_back_e(&envp_s, ft_lstnew_e(name[index], value[index]));
	return (envp_s);
}

t_evnp	*init_envp(char **envp_array)
{
	t_evnp	*envp;
	// int		i;
	char	**names;
	char	**values;

	envp = NULL;
	names = init_names(envp_array);
	values = init_values(envp_array);
	envp = add_info_envp(envp, names, values);
	return (envp);
}

void	print_envp(t_evnp *array)
{
	while (array)
	{
		printf("%s=%s\n", array->name, array->value);
		array = array->next;
	}
}

char	**create_envp(void)
{
	char	**envp;

	envp = (char **)malloc(sizeof(char *) * 3);
	envp[0] = ft_strdup(ft_strjoin("PWD=", getcwd(NULL, 0)));
	envp[1] = ft_strdup("SHLVL=1");
	envp[2] = ft_strdup("_=./minishell");
	envp[3] = NULL;
	return (envp);
}
