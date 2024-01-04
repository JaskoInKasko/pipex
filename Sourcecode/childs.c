#include "../Inc/pipex.h"

void    ft_child_process(t_pipex *pipex, char *argv[], char *envp[])
{
    pipex->child_fd = open(pipex->infile, O_RDONLY);
    if(pipex->child_fd == -1)
        ft_errors(pipex, 4);
    if(dup2(pipex->fd[1], 1) == -1)
        ft_errors(pipex, 5);
    close(pipex->fd[1]);
    close(pipex->fd[0]);
	if(dup2(pipex->child_fd, 0) == -1)
        ft_errors(pipex, 5);
    pipex->cmd_args = ft_split(argv[2], ' ');
    if(!pipex->cmd_args)
        ft_errors(pipex, 6);
    pipex->cmd_path = ft_get_cmd_path(pipex, pipex->paths, pipex->cmd_args);
    if(execve(pipex->cmd_path, pipex->cmd_args, envp) == -1)
        ft_errors(pipex, 9);
}

void    ft_child_process2(t_pipex *pipex, char *argv[], char *envp[])
{
    pipex->child2_fd = open(pipex->outfile,  O_RDWR | O_CREAT | O_TRUNC, 0000644);
    if(pipex->child2_fd == -1)
        ft_errors(pipex, 4);
    if(dup2(pipex->fd[0], 0) == -1)
        ft_errors(pipex, 5);
    close(pipex->fd[0]);
    close(pipex->fd[1]);
	if(dup2(pipex->child2_fd, 1) == -1)
        ft_errors(pipex, 5);
    pipex->cmd_args = ft_split(argv[3], ' ');
    if(!pipex->cmd_args)
        ft_errors(pipex, 6);
    pipex->cmd_path = ft_get_cmd_path(pipex, pipex->paths, pipex->cmd_args);
    if(execve(pipex->cmd_path, pipex->cmd_args, envp) == -1)
        ft_errors(pipex, 9);
}