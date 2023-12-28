#include "../Inc/pipex.h"

void    ft_child_process(t_pipex *pipex, char *argv[])
{
    int fd = open(pipex->infile, O_RDONLY);
    if(fd == -1)
        ft_errors(pipex, 5);
    pipex->cmd_args = ft_split(argv[2], ' ');
    pipex->cmd_path = ft_get_cmd_path(pipex->paths, pipex->cmd_args);
    dup2(fd, 0);
}

void    ft_child_process2(t_pipex *pipex, char *argv[])
{
    int fd = open(pipex->outfile,  O_RDWR, O_CREAT);
    if(fd == -1)
        ft_errors(pipex, 5);
    pipex->cmd_args = ft_split(argv[2], ' ');
    pipex->cmd_path = ft_get_cmd_path(pipex->paths, pipex->cmd_args);
    exit(EXIT_SUCCESS);
    dup2(fd, 1);
}