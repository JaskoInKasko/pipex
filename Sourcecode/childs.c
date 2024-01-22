/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:53:09 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/05 15:53:13 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/pipex.h"

void	ft_child_process(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->child_fd = open(pipex->infile, O_RDONLY);
	if (pipex->child_fd == -1)
		ft_errors(pipex, 5);
	pipex->pipe_dup = dup2(pipex->fd[1], 1);
	if (pipex->pipe_dup == -1)
		ft_errors(pipex, 6);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	pipex->fd_dup = dup2(pipex->child_fd, 0);
	if (pipex->fd_dup == -1)
		ft_errors(pipex, 20);
	close(pipex->child_fd);
	pipex->cmd_args = ft_split(argv[2], ' ');
	if (!pipex->cmd_args)
		ft_errors(pipex, 21);
	pipex->cmd_path = ft_get_cmd_path(pipex, pipex->paths, pipex->cmd_args);
	if (execve(pipex->cmd_path, pipex->cmd_args, envp) == -1)
		ft_errors(pipex, 25);
}

void	ft_child_process2(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->child2_fd = open(pipex->outfile,
			O_RDWR | O_CREAT | O_TRUNC, 0000644);
	if (pipex->child2_fd == -1)
		ft_errors(pipex, 5);
	pipex->pipe_dup = dup2(pipex->fd[0], 0);
	if (pipex->pipe_dup == -1)
		ft_errors(pipex, 6);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	pipex->fd_dup = dup2(pipex->child2_fd, 1);
	if (pipex->fd_dup == -1)
		ft_errors(pipex, 20);
	close(pipex->child2_fd);
	pipex->cmd_args = ft_split(argv[3], ' ');
	if (!pipex->cmd_args)
		ft_errors(pipex, 21);
	pipex->cmd_path = ft_get_cmd_path(pipex, pipex->paths, pipex->cmd_args);
	if (execve(pipex->cmd_path, pipex->cmd_args, envp) == -1)
		ft_errors(pipex, 25);
}
