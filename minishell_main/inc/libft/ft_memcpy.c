/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:39:27 by asitailo          #+#    #+#             */
/*   Updated: 2024/02/22 15:23:31 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	if (!dst && !src)
	{
		return (NULL);
	}
	i = 0;
	while (i < (int)n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

/*
int main(void)
{
    char    s1[] = "H4el4lo";
	char    s2[] = "Heelllo";

    printf("%s", (char *)ft_memcpy(s1, s2, 5));
    return (0);
}
*/
