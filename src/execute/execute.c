/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:54:21 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 18:18:11 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	execution(char *arg, char **args, char **env)
// {
// 	int	res;

// 	res = fork();
// 	if (res == 0)
// 	{
// 		execve(arg, args, env);
// 		exit(0);
// 	}
// 	else if (res > 0)
// 	{
// 		usleep(1000);
// 		printf("Parent process\n");
// 	}
// }

// int	main(void)
// {
// 	char *args[3];
// 	args[0] = "/bin/ls";
// 	args[1] = "-l";
// 	args[2] = NULL;
// 	execution(args[0], args, NULL);
// 	return (0);
// }

void	exec_cmd(t_tools *tool, t_cmd_simple *list)
{
	redir_input_output(list, tool);
	if (g_signal != SIGINT)
	{
		if (call_builtin_func(tool, list))
			exit_shell_no_mes(0, tool);
		else if (list->args_array[0] && find_command_path(tool, list) == NULL
			&& access(list->args_array[0], X_OK) == -1)
			put_to_stderr_and_exit("%s: command not found\n",
				list->args_array[0], tool, 127);
		else if (find_command_path(tool, list) == NULL
			&& find_env_node(tool->envp_list, "PATH"))
			execve(list->args_array[0], list->args_array,
				new_env_array(tool));
		else if (find_command_path(tool, list) == NULL
			&& (!find_env_node(tool->envp_list, "PATH")
				&& ft_strcmp(list->args_array[0], "./minishell") == 0))
			exit_shell_no_free("minishell: minishell: No such file "
				"or directory\n", 127, tool);
		else if (execve(find_command_path(tool, list),
				list->args_array, new_env_array(tool)) < 0)
			exit_shell_no_mes(errno, tool);
		exit_shell_no_mes(errno, tool);
	}
}

void	exec_last_cmd(t_tools *data, t_cmd_simple *cmd)
{
	int	pid;
	int	status;

	status = 0;
	// if (g_signal != SIGINT && list && cmd->redir_status > -1
	if (g_signal != SIGINT && cmd && cmd->redir_status > -1
		&& ((cmd->args_array && cmd->args_array[0])))
	{
		pid = fork();
		if (pid < 0)
			exit_shell_no_mes(errno, data);
		if (pid == 0)
		{
			exec_cmd(data, cmd);
			exit_shell_no_mes(errno, data);
		}
		while (waitpid(-1, &status, 0) > 0)
			continue ;
		data->exit_code = WEXITSTATUS(status);
	}
	if (cmd->fd_in != -1 && close(cmd->fd_in) < 0)
		exit_shell_no_mes(errno, data);
	return_in_out(data);
}

int	check_not_child_exec_builtins(t_cmd_simple *cmd, t_tools *data)
{
	if (cmd && !(cmd->next) && (ft_strcmp(cmd->value, "unset") == 0
			|| ft_strcmp(cmd->value, "export") == 0
			|| ft_strcmp(cmd->value, "cd") == 0
			|| ft_strcmp(cmd->value, "exit") == 0))
	{
		redir_input_output(cmd, data);
		if (g_signal != SIGINT)
			call_builtin_func(data, data->cmd);
		return_in_out(data);
		return (1);
	}
	return (0);
}

void	execution(t_tools *tools)
{
	t_cmd_simple	*cmd;

	cmd = tools->cmd;
	tools->in = dup(0);
	tools->out = dup(1);
	if (tools->in < 0 || tools->out < 0)
		exit_shell_no_mes(errno, tools);
	while (cmd)
	{
		manage_redir(cmd, tools);
		cmd = cmd->next;
	}
	cmd = tools->cmd;
	if (check_not_child_exec_builtins(cmd, tools))
		return ;
	if (cmd && cmd->next && g_signal != SIGINT)
		exec_pipe(tools, cmd);
	else
		exec_last_cmd(tools, cmd);
	while (wait(NULL) > 0)
		continue ;
}
