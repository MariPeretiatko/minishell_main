/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/08 18:17:28 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/08 18:17:28 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


int	is_chr_str(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *haystack_copy;
	char *needle_copy;
	size_t needle_size;

	haystack_copy = (char *)haystack;
	needle_copy = (char *)needle;
	needle_size = ft_strlen(needle_copy);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack_copy && needle_size)
	{
		if (ft_strncmp(haystack_copy, needle_copy, needle_size) == 0)
			return (haystack_copy);
		haystack_copy++;
		needle_copy = (char *)needle;
		needle_size--;
	}
	return (NULL);
}

void	read_input_delim(char *name, int stdin, int stdout, int fd)
{
	char *str;

	signal(SIGINT, handle_sig_child);
	write(stdout, "> ", 2);
	str = get_next_line(stdin);
	while (str && (ft_strncmp(str, name, ft_strlen(name)) != 0
			|| ft_strlen(name) != ft_strlen(str) - 1))
	{
		write(fd, str, ft_strlen(str));
		free(str);
		write(stdout, "> ", 2);
		str = get_next_line(stdin);
	}
	exit(0);
}

int	in_quotes(char *s, int pos)
{
	int double_quotes;
	int single_quotes;
	int i;

	double_quotes = 0;
	single_quotes = 0;
	i = 0;
	while (i <= pos)
	{
		if (s[i] == '\"' && single_quotes % 2 == 0)
			double_quotes++;
		if (s[i] == '\'' && double_quotes % 2 == 0)
			single_quotes++;
		i++;
	}
	if (double_quotes % 2 != 0 || single_quotes % 2 != 0)
		return (1);
	return (0);
}

void	process_input(char *input, char *str, int *i, int *j)
{
	while (input[*i])
	{
		while ((input[*i] == ' ' || input[*i] == '\t') && (input[*i + 1] == ' '
				|| input[*i + 1] == '\t'))
			(*i)++;
		while (input[*i] && in_quotes(input, *i))
			str[(*j)++] = input[(*i)++];
		if (input[*i])
			str[(*j)++] = input[(*i)++];
	}
}

char	*update_input(char *input)
{
	char *new_str;
	int i;
	int j;

	if (!input || !*input)
		return (NULL);
	new_str = ft_calloc(1, ft_strlen(input) + 1);
	if (!new_str)
		exit_shell("Error: malloc failed\n", 1, NULL);
	i = 0;
	j = 0;
	while ((input[i] == ' ' || input[i] == '\t') && input[i])
		i++;
	process_input(input, new_str, &i, &j);
	if (new_str[j] == ' ' || new_str[j] == '\t')
		new_str[j] = '\0';
	return (new_str);
}
