#include "../../minishell.h"

void	reset_data(t_tools *tool)
{
	if (!tool)
		return ;
	free_tokens(&tool->lexer_list);
	free_list(&tool->cmd);
	ft_strdel(&tool->input_line);
}
