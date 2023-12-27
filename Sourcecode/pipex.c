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
#include <errno.h>
#include <stdio.h>

void    ft_pipex_init(t_pipex *pipex)
{
    pipex->pid1 = 0;
    pipex->pid2 = 0;
    pipex->path = NULL;
    pipex->cmd = NULL;
    pipex->cmd_args = NULL;
}

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

int	main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;

    if(argc == 5)
    {
        ft_pipex_init(&pipex);
        pipex.path = ft_find_path(envp);
        pipex.cmd = ft_get_cmd(pipex.path);
        /*int pid = fork();
        if(pid == -1)
            perror("Error:");
        if(pid == 0)
            child_process();
        waitpid(pid, NULL, 0);
        parent_process();*/
    }
    else
    {
        ft_printf("Error: Wrong amount of Arguments! Expected 5!\n");
        ft_printf("Example: file1 cmd1 cmd2 file2\n");
    }
    return (0);
}
