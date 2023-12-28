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

char    *ft_get_cmd_path(char    **paths, char  **cmd_args)
{
    char    *path;

    path = NULL;
    while(*paths != NULL)
    {
        if (ft_strncmp("/usr/bin", *paths, 8) == 0)
        {
            path = ft_strjoin_free(*paths, "/");
            path = ft_strjoin_free(path, cmd_args[0]);
            ft_printf("%s\n", path);
            return (path);
        }
        paths++;
    }
    return (NULL);
}