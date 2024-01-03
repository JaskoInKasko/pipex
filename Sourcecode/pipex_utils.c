#include "../Inc/pipex.h"

char    *ft_find_path(char *envp[])
{
    int i;

    i = 0;
    while(envp[i] != NULL)
    {
        if(ft_strncmp("PATH", envp[i], 4) == 0)
            return (envp[i]);
        i++;
    }
    return (NULL);
}

char    *ft_get_cmd_path(t_pipex *pipex, char **paths, char **cmd_args)
{
    char    *path;
    char    *tmp;

    path = NULL;
    tmp = NULL;
    while(*paths != NULL)
    {
        if (ft_strncmp("/usr/bin", *paths, 8) == 0)
        {
            tmp = ft_strjoin_free(*paths, "/");
            if(!tmp)
                ft_errors(pipex, 7);
            path = ft_strjoin_free(tmp, cmd_args[0]);
            free(tmp);
            /*if(access("", F_OK) != 0)
                ft_errors();*/              //check for file permission 
            return (path);
        }
        paths++;
    }
    return (NULL);
}