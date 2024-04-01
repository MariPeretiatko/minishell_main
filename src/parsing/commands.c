
#include "../../minishell.h"

char	*find_command_path(t_tools *tools, t_cmd_simple *cmd)
{
    char	*command_path;
    char	*path;

    path = find_env_var(tools, "PATH");
    if (!path)
        return (NULL);
    tools->path_cmd = ft_split(path, ':');
    if (!tools->path_cmd)
        return (NULL);
    command_path = find_executable_path(tools->path_cmd, cmd->value);
    free_2darray(tools->path_cmd);
    return (command_path);
}

char	*find_executable_path(char **paths, char *cmd)
{
    char	*tmp;
    char	*dup;
    int		i;
    char	*command;

    i = 0;
    while (paths[i])
    {
        dup = ft_strdup(paths[i]);
        tmp = ft_strjoin(dup, "/");
        free(dup);
        command = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(command, F_OK) == 0)
            return (command);
        free(command);
        i++;
    }
    return (NULL);
}

char	*find_env_var(t_tools *tools, char *name)
{
    t_evnp 	*tmp;

    tmp = tools->envp_list;
    while (tmp)
    {
        if (ft_strcmp(tmp->name, name) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }
    return (NULL);
}

t_evnp	*find_env_node(t_evnp *envp_list, char *name)
{
    t_evnp	*tmp;

    tmp = envp_list;
    while (tmp)
    {
        if (ft_strcmp(tmp->name, name) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}
