#include "../Inc/pipex.h"

void    ft_free_all(t_pipex *pipex, int n)
{
    if(n == 1 || n == 2 || n == 3)
    {   
        while(pipex->paths[pipex->i] != NULL)
        {
            free(pipex->paths[pipex->i]);
            pipex->i++;
        }
        free(pipex->paths);
    }
    if(n == 2 || n == 3)
    {
        pipex->i = 0;
        while(pipex->cmd_args[pipex->i] != NULL)
        {
            free(pipex->cmd_args[pipex->i]);
            pipex->i++;
        }
        free(pipex->cmd_args);
    }
    if(n == 3)
        free(pipex->cmd_path);
    exit(EXIT_FAILURE);
}