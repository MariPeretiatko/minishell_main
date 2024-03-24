/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:16:31 by asitailo          #+#    #+#             */
/*   Updated: 2024/02/22 15:28:54 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_getsize(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		size;

	size = ft_getsize(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	c = (char *)malloc((size + 1) * sizeof(char));
	if (!c)
		return (NULL);
	if (n < 0)
	{
		c[0] = '-';
		n = -n;
	}
	c[size--] = '\0';
	while (n > 0)
	{
		c[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (c);
}
