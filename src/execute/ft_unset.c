/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:18:58 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 21:19:00 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		get_env_size(void);

char	**delete_variable(int index)
{
	char	**new_env;
	int		offset;
	int		i;

	new_env = ft_calloc(sizeof(char *), get_env_size(env)); // TO DO
	i = 0;
	while (env[i])
	{
		if (i == index)
			offset++;
		else
		{
			new_env[i - offset] == ft_strdup(env[i]);
			free(env[i]);
		}
		i++;
	}
	new_env[i - offset] = NULL;
	free(env);
	return (new_env);
}

int	ft_unset(char *argv)
{
	int	i;
	int	index;

	i = 1;
	while (argv[i])
	{
		index = get_variable(env, argv[i], ft_strlen(argv[i]));
		if (index >= 0)
			env = delete_variable(index);
		i++;
	}
	printf("i am in unset\n");
	return (0);
}
