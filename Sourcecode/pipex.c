/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:14:46 by jsakanov          #+#    #+#             */
/*   Updated: 2023/12/25 16:16:58 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/pipex.h"

void	ft_pipex_init(t_pipex *pipex, char *argv[])
{
	pipex->i = 0;
	pipex->i2 = 0;
	pipex->pid1 = 0;
	pipex->pid2 = 0;
	pipex->fd[0] = -1;
	pipex->fd[1] = -1;
	pipex->pipe_dup = -1;
	pipex->fd_dup = -1;
	pipex->child_fd = -1;
	pipex->child2_fd = -1;
	pipex->infile = argv[1];
	pipex->outfile = argv[4];
	pipex->path = NULL;
	pipex->paths = NULL;
	pipex->cmd_path = NULL;
	pipex->cmd_args = NULL;
}

void	ft_get_paths(t_pipex *pipex, char *envp[])
{
	pipex->path = ft_find_path(envp);
	pipex->paths = ft_split(pipex->path, ':');
	if (!pipex->paths)
		ft_errors(pipex, 1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc == 5)
	{
		ft_pipex_init(&pipex, argv);
		ft_get_paths(&pipex, envp);
		if (pipe(pipex.fd) == -1)
			ft_errors(&pipex, 2);
		pipex.pid1 = fork();
		if (pipex.pid1 == -1)
			ft_errors(&pipex, 3);
		if (pipex.pid1 == 0)
			ft_child_process(&pipex, argv, envp);
		pipex.pid2 = fork();
		if (pipex.pid2 == -1)
			ft_errors(&pipex, 4);
		if (pipex.pid2 == 0)
			ft_child_process2(&pipex, argv, envp);
		ft_check_fd(&pipex, 26);
		waitpid(pipex.pid1, NULL, 0);
		waitpid(pipex.pid2, NULL, 0);
		ft_free_all(&pipex, 1);
	}
	ft_errors(&pipex, 0);
	return (0);
}
