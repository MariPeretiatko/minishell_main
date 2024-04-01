/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:30:01 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/01 19:42:35 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	remove_cmd_list(t_cmd_simple *head)
{
	t_cmd_simple	*current;
	t_cmd_simple	*next;
	int				i;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		if (current->args_array != NULL)
		{
			i = 0;
			while (current->args_array[i] != NULL)
			{
				free(current->args_array[i]);
				i++;
			}
			free(current->args_array);
		}
		free(current);
		current = next;
	}
}
// Например,если у вас есть функция для очистки списка redir_list с именем redir_list_free,
// тогда можно вызвать ее так: redir_list_free(current->redir_list);
