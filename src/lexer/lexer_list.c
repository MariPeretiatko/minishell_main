/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:23:15 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:22:46 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_lexer	*ft_lstlast(t_lexer *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstadd_back(t_lexer **lst, t_lexer *new_list)
{
	t_lexer	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	new_list->prev = tmp;
	tmp->next = new_list;
}

t_lexer	*ft_lstnew(int index, char *word)
{
	t_lexer	*new_obj;

	new_obj = (t_lexer *)malloc(sizeof(t_lexer));
	if (new_obj)
	{
		new_obj->index = index;
		new_obj->word = strdup(word);
		new_obj->token = check_token(word);
		new_obj->prev = NULL;
		new_obj->next = NULL;
	}
	return (new_obj);
}

int	ft_lstsize(t_lexer *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	remove_lexer_list(t_lexer *head)
{
	t_lexer	*current;
	t_lexer	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->word);
		free(current);
		current = next;
	}
}
