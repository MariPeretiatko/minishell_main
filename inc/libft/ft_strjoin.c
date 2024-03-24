/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:29:05 by asitailo          #+#    #+#             */
/*   Updated: 2024/02/22 17:44:59 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	void	*position;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	s = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	ft_memcpy(s, (const void *) s1, (size_t)s1_len);
	position = &(*(char *)(s + (int)s1_len));
	ft_memcpy(position, (const void *) s2, (size_t)s2_len);
	*(char *)(s + (int)s1_len + (int)s2_len) = '\0';
	return ((char *)s);
}

/*
int main(void)
{
    char    *s;

    s = ft_strjoin("Hello ", "World");
    printf(s);
    return (0);
}
*/
