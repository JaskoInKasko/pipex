#ifndef PIPEX_H
# define PIPEX_H
# include "../included_functions/libft/libft.h"

typedef struct s_pipex
{
    int     pid1;
    int     pid2;
    char    *path;
    char    *cmd;
    char    *cmd_args;
}   t_pipex;

#endif