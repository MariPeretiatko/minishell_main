/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:52:36 by mperetia          #+#    #+#             */
/*   Updated: 2024/02/22 15:36:34 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_get_new_static_buff(char *static_buff)
{
	char	*new_buff;
	int		count1;
	int		count2;

	count1 = 0;
	while (static_buff[count1] && static_buff[count1] != '\n')
		count1++;
	if (!static_buff[count1])
	{
		free(static_buff);
		return (NULL);
	}
	new_buff = (char *)malloc((ft_strlen(static_buff) - count1 + 1));
	if (!new_buff)
	{
		free(new_buff);
		return (NULL);
	}
	count1++;
	count2 = 0;
	while (static_buff[count1])
		new_buff[count2++] = static_buff[count1++];
	new_buff[count2] = '\0';
	free(static_buff);
	return (new_buff);
}

char	*ft_get_line(char *static_buff)
{
	int		i;
	char	*line;

	i = 0;
	if (!static_buff[i])
		return (NULL);
	while (static_buff[i] && static_buff[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buff[i] && static_buff[i] != '\n')
	{
		line[i] = static_buff[i];
		i++;
	}
	if (static_buff[i] == '\n')
	{
		line[i] = static_buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_data(int fd, char *static_buff)
{
	char	*buff;
	int		bytes_read;

	bytes_read = 1;
	buff = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return (NULL);
	while (!ft_strchr(static_buff, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		static_buff = ft_strjoin_gnl(static_buff, buff);
	}
	free(buff);
	return (static_buff);
}

char	*get_next_line(int fd)
{
	static char	*static_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(static_buff);
		static_buff = NULL;
		return (NULL);
	}
	static_buff = ft_read_data(fd, static_buff);
	if (!static_buff)
	{
		free(static_buff);
		return (NULL);
	}
	line = ft_get_line(static_buff);
	static_buff = ft_get_new_static_buff(static_buff);
	if (!static_buff)
		free(static_buff);
	return (line);
}

// int main()
// {
// 	int fd;
// 	if ((fd = open("text.txt", O_RDONLY))==-1)
// 	{
// 		perror("open failed on file file.dat");
// 		exit(1);
// 	}
// 	for(int i = 0; i < 10; i++)
// 	{
// 		printf("%s", get_next_line(fd));
// 	}
// 	close(fd);
// }