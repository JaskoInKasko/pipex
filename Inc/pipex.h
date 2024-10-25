/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:18:02 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/05 15:18:06 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
//  perror
# include <errno.h>
# include <stdio.h>
//  waitpid / open / fork
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
//  libft
# include "../included_functions/libft/libft.h"

typedef struct s_pipex
{
	int		i;
	int		i2;
	int		fd[2];
	int		pipe_dup;
	int		fd_dup;
	char	*infile;
	char	*outfile;
	int		pid1;
	int		pid2;
	int		child_fd;
	int		child2_fd;
	char	*path;
	char	**paths;
	char	*cmd_path;
	char	**cmd_args;
}			t_pipex;

//      PIPEX_UTILS
char	*ft_find_path(char *envp[]);
char	*ft_get_cmd_path(t_pipex *pipex, char **paths, char **cmd_args);

//      CHILDS
void	ft_child_process(t_pipex *pipex, char *argv[], char *envp[]);
void	ft_child_process2(t_pipex *pipex, char *argv[], char *envp[]);

//      ERRORS
void	ft_errors(t_pipex *pipex, int n);

//      FREE_ALL
void	ft_check_fd(t_pipex *pipex, int n);
void	ft_free_all(t_pipex *pipex, int n);

#endif