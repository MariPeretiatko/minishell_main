# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 14:51:55 by asitailo          #+#    #+#              #
#    Updated: 2024/03/24 23:24:43 by mperetia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
SRCS =	libft/ft_strchr.c\
		libft/ft_atoi.c\
		libft/ft_strcmp.c\
		libft/ft_strncmp.c\
		libft/ft_memcpy.c\
		libft/ft_putstr_fd.c\
		libft/ft_strdup.c\
		libft/ft_strjoin.c\
		libft/ft_strlen.c\
		libft/ft_split.c\
		libft/ft_itoa.c\
		libft/ft_strdel.c\
		libft/ft_strcpy.c\
		libft/ft_calloc.c\
		libft/ft_bzero.c\
		libft/ft_substr.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
