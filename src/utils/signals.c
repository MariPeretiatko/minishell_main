/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/03/24 20:43:37 by mperetia          #+#    #+#             */
/*   Updated: 2024/03/24 20:43:37 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_signal(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_c;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	rl_catch_signals = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGCHLD, &sa, NULL);
}

void	handle_c(int signo)
{
	int sig;

	if (signo == SIGCHLD)
        global_signal = SIGCHLD;
	else if (signo == SIGINT)
	{
		write(1, "\n", 1);
		wait(NULL);
		sig = global_signal;
        global_signal = SIGINT;
		if (sig == SIGCHLD)
			return ;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = 0;
	}
	else if (signo == SIGQUIT)
		wait(NULL);
}

int	handle_d(t_tools *tool, char *line)
{
	if (line == NULL)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		free_data(tool);
		exit(0);
	}
	else if (ft_strlen(line) == 0)
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

void	handle_sig_child(int signo)
{
	if (signo == SIGINT)
	{
        global_signal = SIGINT;
		exit(1);
	}
}
