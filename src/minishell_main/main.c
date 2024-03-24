// #include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// #include <stdlib.h>

#include "../../minishell.h"

void delete_tools(t_tools *tools)
{
	remove_lexer_list(tools->lexer_list);
	// remove_cmd_list(tools->cmd);
	ft_strdel(&tools->input_line);
}

void	minishell_loop(t_tools *tools)
{
	char	*input;

	// t_lexer	*l;
	// t_cmd_simple *cmd;
	// t_lexer *head;
	// input = (*tools)->input_line;
	while (1)
	{
		// delete_tools(tools);
		input = readline(tools->minishell);
		if  (ft_strlen(input) > 0)
			add_history(input);
		
		//TO DO quotes
		// ((*tools)->input_line = readline((*tools)->minishell));
		// printf("%s\n", (*tools)->input_line);
		// print_lexer(&(*tools)->lexer_list);
		tools->input_line = ft_strdup(input);
		tools->lexer_list = init_lexer(tools->input_line);
		init_path(tools);
		// init_path(tools);
		// printenvp((*tools)->envp_list);
		// add_history((*tools)->input_line);
		// l = init_lexer((*tools)->input_line)
		// print_lexer(&tools->lexer_list);
		// printf("I am here!\n");
		// ft_builtin((*tools), cmd);
		// (*tools)->lexer_list = l;
		// print_lexer((*tools)->lexer_list);
		// printenvp((*tools)->export_list);
		// (*tools)->lexer_list = init_lexer((*tools)->input_line);
		// print_lexer((*tools)->lexer_list);
		// printf("%s", input);
		// Обработка введенной строки (здесь может быть ваша логика)
		// printf("size = %d\n", ft_lstsize(lexer));
		// Принудительное обновление отображения
		// rl_redisplay();
		// printf("(*tools)->input_line %s\n", (*tools)->input_line);
		// Освобождение памяти, выделенной readline
		// remove_lexer_list(tools->lexer_list);
		// tools->lexer_list = NULL;
		delete_tools(tools);
		free(tools->input_line);
		free(input);
		// free((*tools)->lexer_list);
	}
}

int	main(int ac, char *av[], char *envp[])
{
	t_tools	*tools;

	(void)ac;
	(void)av;
	// printf("%s\n", getenv("USER"));
	init_tools(&tools, envp);
	// init_cmd_simple(&tools->cmd);
	minishell_loop(tools);
	// execve();
	// char *filename = "/bin/ls";
	// // Аргументы для ls: -l
	// char *const argv[] = { "ls", "-l", NULL };
	// // Переменные окружения
	// // char *const envp[] = { NULL };
	// // Вызов execve для выполнения ls -l
	// execve(NULL, argv, envp);
	// // Если execve вернул управление, что-то пошло не так
	// perror("execve");
	// t_evnp *envp_s;
	// envp_s = init_en(envp);
	// printenvp(envp_s);
	// print_envp(envp);
	// execve();
	// print_envp(envp);
	return (0);
}
