/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:29:28 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/02 18:41:02 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_lexer(t_tools *tools, char *input)
{
	if (!input || !input[0])
		return (1);
	tools->lexer_list = init_lexer(input);
	if (cheak(tools))
		return (1);
	return (0);
}

int	check(t_tools *tools)
{
	// find_redirect(tools->lexer_list);
	if (error_syntax(tools->lexer_list, tools))
		return (1);
	return (0);
}

int	error_syntax(t_lexer *lexer, t_tools *tools)
{
	char	*str;
	int		i;

	i = 0;
	while (lexer)
	{
		str = check_first_token(&tools->input_line[i], &i);
		if (str == NULL)
			return (0);
		while (lexer->token == WORD)
			lexer = lexer->next;
		if (check_red(lexer) || check_pipe(token))
			return (1);
		lexer = lexer->next;
	}
	return (0);
}

// char	*check_token(char *str, int *i)
// {
// 	if (*str == '|')
// 		return (*i += 1, "|");
// 	if (*str == '<' && *(str + 1) == '>')
// 		return (*i += 2, "<>");
// 	if (*str == '>' && *(str + 1) == '>')
// 		return (*i += 2, ">>");
// 	if (*str == '>')
// 		return (*i += 1, ">");
// 	if (*str == '<' && *(str + 1) == '<' && *(str + 2) != '>')
// 		return (*i += 2, "<<");
// 	if (*str == '<')
// 		return (*i += 1, "<");
// 	return (NULL);
// }

char	*check_first_token(char *str, int *i)
{
	char	*result;

	while (*str)
	{
		result = check_token(str, i);
		if (result != NULL)
			return (result);
		str++;
		(*i)++;
	}
	return (NULL);
}