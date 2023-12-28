#ifndef PIPEX_H
# define PIPEX_H
//  perror
#include <errno.h>
#include <stdio.h>
//  waitpid / open
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
//  libft
# include "../included_functions/libft/libft.h"

typedef struct s_pipex
{
    int     pid1;
    int     pid2;
    char    *infile;
    char    *outfile;
    char    *path;
    char    **paths;
    char    *cmd_path;
    char    **cmd_args;
}   t_pipex;

//      PIPEX_UTILS
char    *ft_find_path(char *envp[]);
char    *ft_get_cmd_path(char    **paths, char  **cmd_args);

//      CHILDS
void    ft_child_process(t_pipex *pipex, char *argv[]);
void    ft_child_process2(t_pipex *pipex, char *argv[]);

//      ERRORS
void    ft_errors(t_pipex *pipex, int n);

#endif