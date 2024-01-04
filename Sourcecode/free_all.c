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
        while(pipex->cmd_args[pipex->i2] != NULL)
        {
            free(pipex->cmd_args[pipex->i2]);
            pipex->i2++;
        }
        free(pipex->cmd_args);
    }
    if(pipex->fd[0] != 0 || pipex->fd[1] != 0
        || pipex->fd[0] != -1 || pipex->fd[1] != -1)
    {
    close(pipex->fd[0]);
    close(pipex->fd[1]);
    }
    if(n == 3)
        free(pipex->cmd_path);
    exit(EXIT_FAILURE);
}