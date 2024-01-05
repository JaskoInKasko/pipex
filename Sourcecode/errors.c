/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:05:44 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/05 16:05:47 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/pipex.h"

void	ft_errors2(t_pipex *pipex, int n)
{
	if (n == 20)
		ft_putstr_fd("Error!\nSecond dup2() function has failed!\n",
			STDERR_FILENO);
	if (n == 20)
		ft_free_all(pipex, 20);
	if (n == 21)
		ft_putstr_fd("Error!\nChild split() function has failed!\n",
			STDERR_FILENO);
	if (n == 21)
		ft_free_all(pipex, 21);
	if (n == 22)
		ft_putstr_fd("Error!\nFirst ft_strjoin_free function has failed!\n",
			STDERR_FILENO);
	if (n == 23)
		ft_putstr_fd("Error!\nSecond ft_strjoin_free function has failed!\n",
			STDERR_FILENO);
	if (n == 24)
		ft_putstr_fd("Error!\nCommand not found!\n", STDERR_FILENO);
	if (n == 22 || n == 23 || n == 24)
		ft_free_all(pipex, 22);
	if (n == 25)
		ft_putstr_fd("Error!\nexecve() function has failed!\n",
			STDERR_FILENO);
	if (n == 25)
		ft_free_all(pipex, 25);
}

void	ft_errors(t_pipex *pipex, int n)
{
	if (n == 0)
	{
		ft_printf("Error: Wrong amount of Arguments! Expected 4!\n");
		ft_printf("Example: file1 cmd1 cmd2 file2\n");
		return ;
	}
	if (n == 1)
		ft_putstr_fd("Error!\nParent split() function has failed!\n",
			STDERR_FILENO);
	if (n == 1)
		exit(EXIT_FAILURE);
	if (n == 2)
		ft_putstr_fd("Error! pipe() function failed!\n", STDERR_FILENO);
	if (n == 3)
		ft_putstr_fd("Error! fork() function failed!\n", STDERR_FILENO);
	if (n == 4)
		ft_putstr_fd("Error!\nInfile: Failed to open the file!\n",
			STDERR_FILENO);
	if (n == 5)
		ft_putstr_fd("Error!\nFirst dup2() function has failed!\n",
			STDERR_FILENO);
	if (n == 2 || n == 3 || n == 4 || n == 5)
		ft_free_all(pipex, 1);
	ft_errors2(pipex, n);
}
