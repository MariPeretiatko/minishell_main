/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:21:33 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/02 00:35:43 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
//???? useless
void	find_redir(t_lexer **head)
{
	t_lexer	*current;
	t_lexer	*tmp;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (tmp->token == GREATER && tmp->next->token == GREATER)
			find_delim(tmp);
		else if (tmp->token == LESS && tmp->next->token == LESS)
			find_append(tmp);
		current = current->next;
	}
}

void	find_delim(t_lexer *current)
{
	t_lexer	*tmp;
	t_lexer	*tmp2;

	tmp = current;
	if (tmp->type == GREATER && tmp->next->type == GREATER)
	{
		tmp->type = T_DELIM;
		ft_strdel(&tmp->word);
		tmp->word = ft_strdup("<<");
		tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->prev = tmp;
		ft_strdel(&tmp2->word);
		free(tmp2);
	}
}

void	find_append(t_lexer *current)
{
	t_lexer	*tmp;
	t_lexer	*tmp2;

	tmp = current;
	if (tmp->type == T_RED_OUT && tmp->next->type == T_RED_OUT)
	{
		tmp->type = T_APPEND;
		ft_strdel(&tmp->word);
		tmp->word = ft_strdup(">>");
		tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->prev = tmp;
		ft_strdel(&tmp2->word);
		free(tmp2);
	}
}
