
#include "../../minishell.h"

void	add_str_part(char *str, int i, int start, char **result)
{
    char	*new_str;
    char	*dup;

    new_str = malloc(i - start + 1);
    ft_strlcpy(new_str, &str[start], i - start + 1);
    dup = ft_strdup(*result);
    free(*result);
    *result = ft_strjoin(dup, new_str);
    free(dup);
    free(new_str);
}

void	join_result_with_exit(int exit_status, char **result)
{
    char	*exit;
    char	*dup;

    exit = ft_itoa(exit_status);
    dup = ft_strdup(*result);
    free(*result);
    *result = ft_strjoin(dup, exit);
    free(dup);
    free(exit);
}

void	replace_variable(t_tools *tools, int *i, int *start, char **result)
{
    char	*new_str;
    char	*str;
    char	*dup;

    str = tools->input_line;
    add_str_part(str, *i, *start, result);
    *start = ++(*i);
    while (str[*i] && (str[*i] == '_' || ft_isalnum(str[*i])))
        (*i)++;
    new_str = malloc(*i - *start + 1);
    ft_strlcpy(new_str, &str[*start], *i - *start + 1);
    dup = ft_strdup(*result);
    free(*result);
    *result = ft_strjoin(dup, find_env_var(tools, new_str));
    free(dup);
    free(new_str);
    *start = *i;
}

char	*replace_dollars(t_tools *tools, char *str)
{
    int		start;
    char	*result;
    int		i;

    start = 0;
    i = 0;
    result = NULL;
    while (str[i])
    {
        if (str[i] == '$' && str[i + 1] == '?' && !in_single_quotes(str, i))
        {
            add_str_part(str, i, start, &result);
            i += 2;
            join_result_with_exit(tools->exit_code, &result);
            start = i;
        }
        else if (str[i] == '$' && str[i + 1] != ' '
                 && !in_single_quotes(str, i))
            replace_variable(tools, &i, &start, &result);
        else
            i++;
    }
    add_str_part(str, i, start, &result);
    free(str);
    return (result);
}
