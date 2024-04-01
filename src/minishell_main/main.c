// #include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// #include <stdlib.h>

#include "../../minishell.h"

void delete_tools(t_tools *tools)
{
    if (!tools)
        return ;
    free_tokens(&tools->lexer_list);
    free_list(&tools->cmd);
    ft_strdel(&tools->input_line);
}

void	minishell_loop(t_tools *tools)
{
	char	*input;

	while (1)
	{
        g_signal = 0;
		delete_tools(tools);
		input = readline(tools->minishell);
        if (handle_d(tools, input))
            continue ;
		if  (ft_strlen(input) > 0)
			add_history(input);
		tools->input_line = trim_input(input);
        tools->input_line = replace_dollars(tools, tools->input_line);
        ft_strdel(&input);
        if ((odd_quote(tools->input_line)) || (special_chars(tools->input_line))
            || (lexical_analysis(tools, tools->input_line)))
            continue ;
        fix_quotes(tools);
        init_tools(tools);
        exec_pipes(tools);
	}
}

int	main(int ac, char *av[], char *envp[])
{
	t_tools	*tools;

	(void)ac;
	(void)av;
	init_tools(&tools, envp);
    handle_signal();
	minishell_loop(tools);
    free_tools(tools);
	return (0);
}
