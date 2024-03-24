/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:56:11 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:11:42 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	print_names(char **array) //tmp
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 		printf("%s\n", array[i++]);
// }

// void	print_values(char **array) //tmp
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 		printf("%s\n", array[i++]);
// }

// tmp for delete
void	print_envp_(char **envp)
{
	while (*envp)
	{
		printf("%s\n", *envp++);
	}
}

t_evnp	*ft_lstlast_e(t_evnp *lst)
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

void	ft_lstadd_back_e(t_evnp **lst, t_evnp *new)
{
	t_evnp	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
}

t_evnp	*ft_lstnew_e(char *name, char *value)
{
	t_evnp	*new_obj;

	new_obj = (t_evnp *)malloc(sizeof(t_evnp));
	if (new_obj)
	{
		new_obj->name = name;
		new_obj->value = value;
		new_obj->prev = NULL;
		new_obj->next = NULL;
	}
	return (new_obj);
}
