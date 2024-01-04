#include "../Inc/pipex.h"

void    ft_free_all(t_pipex *pipex, int n)
{
    if(n == 1 || n == 2 || n == 20 || n == 21
        || n == 22 || n == 23 || n == 24 || n == 25)
    {
        while(pipex->paths[pipex->i] != NULL)
        {
            free(pipex->paths[pipex->i]);
            pipex->i++;
        }
        free(pipex->paths);
    }
    if(n == 2 || n == 22 || n == 24 || n == 25)
    {
        while(pipex->cmd_args[pipex->i2] != NULL)
        {
            free(pipex->cmd_args[pipex->i2]);
            pipex->i2++;
        }
        free(pipex->cmd_args);
    }
    if(n != 20 && n != 21 && n != 22 && n != 23
        && n != 24 && n != 25)
    {   
        close(pipex->fd[0]);
        close(pipex->fd[1]);
    }
    if(pipex->pipe_dup != -1)
        close(pipex->pipe_dup);
    if(pipex->fd_dup != -1)
        close(pipex->fd_dup);
    if(n != 21 && n != 22 && n != 23 && n != 24 && n != 25)
    {   
        if(pipex->child_fd != -1)
            close(pipex->child_fd);
        if(pipex->child2_fd != -1)
            close(pipex->child2_fd);
    }
    if(n == 25)
        free(pipex->cmd_path);
    exit(EXIT_FAILURE);
}