/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:59:13 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 21:15:18 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_pwd(void)
{
	char	cwd[256];
	int		res;

	if (getcwd(cwd, sizeof(cwd)))
		res = 0;
	else
		res = 1;
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	return (res);
}
