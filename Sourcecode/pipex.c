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

void    ft_pipex_init(t_pipex *pipex, char *argv[])
{
    pipex->pid1 = 0;
    pipex->pid2 = 0;
    pipex->infile = argv[1];
    pipex->outfile = argv[4];
    pipex->path = NULL;
    pipex->cmd_args = NULL;
}

void    ft_get_paths_and_cmds(t_pipex *pipex, char *argv[], char *envp[])
{
        pipex->path = ft_find_path(envp);
        pipex->paths = ft_split(pipex->path, ':');
}

int	main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;

    if(argc == 5)
    {
        ft_pipex_init(&pipex, argv);
        ft_get_paths_and_cmds(&pipex, argv, envp);
        pipex.pid1 = fork();
        if (pipex.pid1 == -1)
            perror("Error:");
        if (pipex.pid1 == 0)
            ft_child_process(&pipex, argv);
        pipex.pid2 = fork();
        if (pipex.pid1 == -1)
            perror("Error:");
        if (pipex.pid2 == 0)
            ft_child_process2(&pipex, argv);
    }
    else
    {
        ft_printf("Error: Wrong amount of Arguments! Expected 4!\n");
        ft_printf("Example: file1 cmd1 cmd2 file2\n");
    }
    return (0);
}