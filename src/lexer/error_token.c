/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:06:58 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/02 00:14:21 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_pipe(t_lexer *tmp)
{
	if (tmp->token == T_PIPE && (tmp->next->type == T_NEWLINE || !tmp->prev))
	{
		printf("minishell> syntax error near %s\n", "unexpected token `|'");
		return (1);
	}
	return (0);
}

int	check_red(t_token *token)
{
	if ((token->type == T_RED_INP || token->type == T_RED_OUT
			|| token->type == T_APPEND || token->type == T_DELIM)
		&& token->next->type != T_WORD)
	{
		if (token->next->type != T_WORD || !token->prev
			|| token->prev->type != T_WORD)
		{
			printf("minishell> syntax error near unexpected token `%s'\n",
				token->next->word);
			return (1);
		}
	}
	return (0);
}
