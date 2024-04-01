/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:17:49 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/02 00:13:57 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_lexer(t_lexer **lexer)
{
	int		i;
	t_lexer	*head;

	i = 0;
	head = *lexer;
	if (head != NULL)
	{
		while (head)
		{
			printf("\t[%d]\n", i);
			printf("[%d] lexer->index- %d\n", i, head->index);
			printf("[%d] lexer->word- %s\n", i, head->word);
			printf("[%d] lexer->token- %d\n", i, head->token);
			printf("[%d] lexer->prev- %p\n", i, head->prev);
			printf("[%d] lexer->next- %p\n\n", i, head->next);
			i++;
			head = head->next;
		}
	}
}

int	check_token(char *token)
{
	if (!ft_strcmp(token, "|"))
		return (PIPE);
	else if (!ft_strcmp(token, "<"))
		return (GREATER);
	else if (!ft_strcmp(token, "<<"))
		return (GREATER_GREATER);
	else if (!ft_strcmp(token, ">"))
		return (LESS);
	else if (!ft_strcmp(token, ">>"))
		return (LESS_LESS);
	return (WORD);
}

// lexer = add_info_lexer(&lexer, array_str);
t_lexer	*init_lexer(char *str)
{
	t_lexer	*lexer;
	int		index;
	char	**array_str;
	int		i;

	i = 0;
	index = 0;
	lexer = NULL;
	array_str = ft_split(str, ' ');
	if (!lexer)
		lexer = ft_lstnew(index, array_str[index]);
	while (array_str[++index])
		ft_lstadd_back(&lexer, ft_lstnew(index, array_str[index]));
	while (array_str[i])
	{
		free(array_str[i]);
		array_str[i] = NULL;
	}
	free(array_str);
	return (lexer);
}
