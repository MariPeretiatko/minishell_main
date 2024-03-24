/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:23:12 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 21:38:40 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// Функция для выделения памяти под массив строк
// char **allocate_memory(size_t size)
// {
//     char **array = malloc(sizeof(char *) * size);
//     if (!array)
//         return (NULL);
//     return (array);
// }
// Функция для копирования строки длиной не более n символов в новую область памяти
char	*copy_string_n(const char *source, size_t n)
{
	char *destination = malloc(n + 1);
	if (!destination)
		return (NULL);
	strncpy(destination, source, n);
	destination[n] = '\0';
	return (destination);
}

// Функция для копирования строки в новую область памяти
char	*copy_string(const char *source)
{
	size_t	length;
	char	*destination;

	length = ft_strlen(source);
	destination = malloc(length + 1);
	if (!destination)
		return (NULL);
	ft_strcpy(destination, source);
	return (destination);
}

// Функция для копирования имени переменной из строки окружения
char	*copy_variable_name(const char *source)
{
	size_t	length;

	length = strcspn(source, "=");
	return (copy_string_n(source, length));
}

// Функция для копирования значения переменной из строки окружения
char	*copy_variable_value(const char *source)
{
	char	*value_start;

	value_start = ft_strchr(source, '=') + 1;
	return (copy_string(value_start));
}

// Функция для освобождения памяти, выделенной под массив строк
void	free_memory(char **array)
{
	char	**ptr;

	ptr = array;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(array);
}

// Функция для создания массива имен переменных окружения
char	**init_names(char **envp_array)
{
	char	**array;
	char	**temp;

	temp = envp_array;
	while (*temp)
		temp++;
	array = malloc(temp - envp_array + 1);
	if (!array)
		return (NULL);
	temp = envp_array;
	while (*temp)
	{
		array[temp - envp_array] = copy_variable_name(*temp);
		if (!array[temp - envp_array])
		{
			free_memory(array);
			return (NULL);
		}
		temp++;
	}
	*temp = NULL;
	return (array);
}

// Функция для создания массива значений переменных окружения
char	**init_values(char **envp_array)
{
	char	**array;
	char	**temp;
	char	*value_start;

	temp = envp_array;
	while (*temp)
		temp++;
	array = malloc(temp - envp_array + 1);
	if (!array)
		return (NULL);
	temp = envp_array;
	while (*temp)
	{
		value_start = ft_strchr(*temp, '=') + 1;
		array[temp - envp_array] = copy_string(value_start);
		if (!array[temp - envp_array])
		{
			free_memory(array);
			return (NULL);
		}
		temp++;
	}
	*temp = NULL;
	return (array);
}
