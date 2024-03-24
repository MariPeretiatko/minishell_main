#include "../../minishell.h"


char	*put_str_to_str(char *dest, char *src, t_tools *tool)
{
	int dest_i;
	int src_i;
	int result_i;
	char *result;

	dest_i = 0;
	src_i = 0;
	result_i = 0;
	result = malloc(ft_strlen(dest) + ft_strlen(src) - 1);
	if (!result)
		exit_shell("Error: malloc failed", errno, tool);
	while (dest && dest[dest_i] && dest[dest_i] != '%')
		result[result_i++] = dest[dest_i++];
	dest_i += 2;
	while (src && src[src_i])
		result[result_i++] = src[src_i++];
	while (dest && dest[dest_i])
		result[result_i++] = dest[dest_i++];
	result[result_i] = '\0';
	return (result);
}

void	put_to_stderr(char *dest, char *src, t_tools *tool, int err)
{
	char *str;

	str = put_str_to_str(dest, src, tool);
	ft_putstr_fd(str, tool->in);
	free(str);
	tool->exit_code = err;
}

void	put_to_stderr_and_exit(char *dest, char *src, t_tools *tool, int err)
{
	char *str;

	str = put_str_to_str(dest, src, tool);
	ft_putstr_fd(str, STDERR_FILENO);
	free(str);
	tool->exit_code = err;
	free_data(tool);
	exit(err);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
