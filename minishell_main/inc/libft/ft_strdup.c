/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:32:58 by asitailo          #+#    #+#             */
/*   Updated: 2024/02/22 15:25:05 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	i;

	i = ft_strlen((char *)src);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	ft_memcpy(res, src, i + 1);
	return (res);
}

/*
int	main(void)
{
	printf("%s\n", ft_strdup("hello"));
	return (0);
}
*/
