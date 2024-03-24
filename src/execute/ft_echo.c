/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:56:17 by mperetia          #+#    #+#             */
/*   Updated: 2024/02/22 15:57:22 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ???
// void	echo_putstr_fd(char *out, int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (out[i])
// 	{
// 		if (out[i] == '\\')
// 			i++;
// 		write(fd, &out[i], 1);
// 		i++;
// 	}
// }
// ???

int	check_echo(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] != '-')
	{
		return (0);
	}
	while (argv[i])
	{
		if (argv[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **argv)
{
	int	new_line;
	int	i;

	new_line = 0;
	i = 1;
	if (!argv[0])
		return (0);
	while (argv[i] && check_echo(argv[i]))
	{
		new_line = 1;
		i++;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!new_line)
		ft_putstr_fd("\n", 1);
	return (0);
}
