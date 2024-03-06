/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:35:40 by mperetia          #+#    #+#             */
/*   Updated: 2024/02/26 16:41:30 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t		ft_strchr(char *str, char c);
int			ft_strcmp(char *str1, char *str2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
// static void	ft_print_digit(const char *str, size_t i, size_t *res);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
void		ft_strdel(char **s);

// get_next_line
char		*get_next_line(int fd);
char		*ft_strjoin_gnl(char *static_buff, char *buff);
// size_t	ft_strlen_gnl(char *s);

#endif