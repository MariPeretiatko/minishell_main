/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:25:50 by asitailo          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:45 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// int	ft_isspace(char s)
// {
// 	if (s == '\t' || s == '\v' || s == '\n')
// 	{
// 		return (1);
// 	}
// 	else if (s == ' ' || s == '\r' || s == '\f')
// 	{
// 		return (1);
// 	}
// 	return (0);
// }

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	sign;
// 	int	number;

// 	i = 0;
// 	sign = 1;
// 	number = 0;
// 	while (ft_isspace(str[i]))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 		{
// 			sign *= -1;
// 		}
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		number = (number * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (number * sign);
// }

//my vesion
static void	ft_print_digit(const char *str, size_t i, size_t *res)
{
	if (str + i && (*(str + i) >= '0' && *(str + i) <= '9'))
	{
		*res *= 10;
		*res += *(str + i) - '0';
		i++;
		return (ft_print_digit(str, i, res));
	}
	else
		return ;
}

static int	ft_check_spaces(const char *str)
{
	if (str && (*str == ' ' || *str == '\n'
			|| *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\f'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_check_spaces(str + i))
		i++;
	if (*(str + i) == '+')
		i++;
	else if (*(str + i) == '-')
	{
		sign = -1;
		i++;
	}
	if (!(*(str + i) >= '0' && *(str + i) <= '9'))
		return (0);
	ft_print_digit(str + i, 0, &res);
	return (res * sign);
}