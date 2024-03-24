/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:52:33 by mperetia          #+#    #+#             */
/*   Updated: 2024/02/22 15:33:45 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// size_t	ft_strlen_gnl(char *s)
// {
// 	size_t	counter;

// 	counter = 0;
// 	if (!s)
// 	{
// 		return (0);
// 	}
// 	while (s[counter] != '\0')
// 	{
// 		counter ++;
// 	}
// 	return (counter);
// }

char	*ft_strjoin_gnl(char *static_buff, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!static_buff)
	{
		free(static_buff);
		static_buff = (char *)malloc(1 * sizeof(char));
		static_buff[0] = '\0';
	}
	if (!static_buff || !buff)
		return (NULL);
	str = malloc(((ft_strlen(static_buff) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (static_buff)
		while (static_buff[++i] != '\0')
			str[i] = static_buff[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(static_buff) + ft_strlen(buff)] = '\0';
	free(static_buff);
	return (str);
}

// char	*ft_strchr(char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	if (c == '\0')
// 		return ((char *)&s[ft_strlen(s)]);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char) c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	return (0);
// }
