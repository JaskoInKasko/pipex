/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:56:27 by jsakanov          #+#    #+#             */
/*   Updated: 2024/01/05 15:56:31 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/pipex.h"

char	*ft_find_path(char *envp[])
{
	while (*envp != NULL)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*ft_get_cmd_path(t_pipex *pipex, char **paths, char **cmd_args)
{
	char	*path;
	char	*tmp;

	path = NULL;
	tmp = NULL;
	while (*paths != NULL)
	{
		pipex->i++;
		tmp = ft_strjoin_free(*paths, "/");
		if (!tmp)
			ft_errors(pipex, 22);
		path = ft_strjoin_free(tmp, cmd_args[0]);
		if (!path)
			ft_errors(pipex, 23);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		paths++;
	}
	ft_errors(pipex, 24);
	return (NULL);
}
