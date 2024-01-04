#include "../Inc/pipex.h"

char    *ft_find_path(char *envp[])
{
    while(*envp != NULL)
    {
        if(ft_strncmp("PATH", *envp, 4) == 0)
            return (*envp + 5);
        envp++;
    }
    return (NULL);
}

char    *ft_get_cmd_path(t_pipex *pipex, char **paths, char **cmd_args)
{
    (void)cmd_args;
    char    *path;
    char    *tmp;

    path = NULL;
    tmp = NULL;
    while(*paths != NULL)
    {
        pipex->i++;
        tmp = ft_strjoin_free(*paths, "/");
        if(!tmp)
            ft_errors(pipex, 7);
        path = ft_strjoin_free(tmp, cmd_args[0]);
        if(!path)
            ft_errors(pipex, 8);
        if(access(path, F_OK) == 0)
            return (path);
        free(path);
        paths++;
    }
    ft_errors(pipex, 10);
    return (NULL);
}