#include "../../minishell.h"

void	free_envir(t_evnp *envir)
{
	t_evnp	*tmp;

	if (!envir)
		return ;
	tmp = envir;
	if (tmp->name)
	{
		free(tmp->value);
		tmp->name = NULL;
	}
	if (tmp->value)
	{
		free(tmp->value);
		tmp->value= NULL;
	}
	free(tmp);
}

void	free_2darray(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		ft_strdel(&array[i]);
	free(array);
	array = NULL;
}

void	ft_envclear(t_evnp **env_list)

{
	t_evnp	*head;

	while ((*env_list))
	{
		head = (*env_list)->next;
		if ((*env_list)->name)
		{
			free((*env_list)->name);
			(*env_list)->name = NULL;
		}
		if ((*env_list)->value)
		{
			free((*env_list)->value);
			(*env_list)->value = NULL;
		}
		free((*env_list));
		(*env_list) = NULL;
		(*env_list) = head;
	}
}
