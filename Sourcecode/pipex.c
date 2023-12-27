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

int	main(int argc, char *argv[], char *envp[])
{
    if(argc == 5)
    {

    }
    else
        perror("Here");
        ft_printf("Error: Wrong amount of Arguments! Expected 5!\n");
    return (0);
}
