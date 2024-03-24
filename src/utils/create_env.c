// #include "../../minishell.h"

// char	**create_envp(void)
// {
// 	char	**envp;

// 	envp = (char **)malloc(sizeof(char *) * 4);
// 	envp[0] = ft_strdup(ft_strjoin("PWD=", getcwd(NULL, 0)));
// 	envp[1] = ft_strdup("SHLVL=1");
// 	envp[2] = ft_strdup("_=./minishell");
// 	envp[3] = NULL;
// 	return (envp);
// }
