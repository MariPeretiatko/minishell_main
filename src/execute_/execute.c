/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:54:21 by mperetia          #+#    #+#             */
/*   Updated: 2024/02/22 15:54:31 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	execution(char *arg, char **args, char **env)
{
	int	res;

	res = fork();
	if (res == 0)
	{
		execve(arg, args, env);
		exit(0);
	}
	else if (res > 0)
	{
		usleep(1000);
		printf("Parent process\n");
	}
}

// int	main(void)
// {
// 	char *args[3];
// 	args[0] = "/bin/ls";
// 	args[1] = "-l";
// 	args[2] = NULL;
// 	execution(args[0], args, NULL);
// 	return (0);
// }