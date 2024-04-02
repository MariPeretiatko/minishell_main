/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:12:43 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/02 22:15:48 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	in_quotes_token(char *s, int *start)
{
	int		double_quotes;
	int		single_quotes;
	bool	encounter;
	int		i;

	double_quotes = 0;
	single_quotes = 0;
	encounter = false;
	i = (*start);
	while (s[++i])
	{
		if (s[i] == '\"' && single_quotes % 2 == 0)
			double_quotes++;
		if (s[i] == '\'' && double_quotes % 2 == 0)
			single_quotes++;
		if ((s[i] == '\'' || s[i] == '\"') && !encounter)
		{
			encounter = true;
			(*start) = i;
		}
	}
	if ((double_quotes % 2 == 0 && double_quotes > 0)
		|| (single_quotes % 2 == 0 && single_quotes > 0))
		return (1);
	return (0);
}

void	trim_tokens_helper(bool *encounter, int *i, int **end)

{
	(**end) = (*i) - 2;
	(*i)++;
	(*encounter) = true;
}

char	*trim_tokens(char *input, int start, int *end)
{
	char	*str;
	char	quote;
	bool	encounter;
	int		i;
	int		j;

	str = ft_calloc(ft_strlen(input) + 1, 1);
	if (!str)
		exit_shell_no_mes(1, NULL);
	quote = input[start];
	encounter = false;
	i = 0;
	j = 0;
	while (i != start)
		str[(j)++] = input[(i)++];
	i++;
	while (input[i])
	{
		if (input[i] == quote && !encounter)
			trim_tokens_helper(&encounter, &i, &end);
		if (input[i])
			str[j++] = input[i++];
	}
	str[j] = '\0';
	return (str);
}

void	fix_quotes(t_tools *tools)
{
	t_lexer	*head;
	char	*tmp;
	int		start;
	int		end;

	head = tools->lexer_list;
	tmp = NULL;
	while (tools->lexer_list)
	{
		if (tools->lexer_list->token == WORD)
		{
			start = -1;
			while (in_quotes_token(tools->lexer_list->word, &start))
			{
				tmp = trim_tokens(tools->lexer_list->word, start, &end);
				ft_strdel(&tools->lexer_list->word);
				tools->lexer_list->word = ft_strdup(tmp);
				ft_strdel(&tmp);
				start = end;
			}
		}
		tools->lexer_list = tools->lexer_list->next;
	}
	tools->lexer_list = head;
}