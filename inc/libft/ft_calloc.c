/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:02:10 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 16:28:06 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *s;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	s = (void *)malloc(count * size);
	if (s == 0)
	{
		return (0);
	}
	ft_bzero(s, (count * size));
	return (s);
}