#include "../Inc/pipex.h"

void    ft_errors(t_pipex *pipex, int n)
{
    (void)pipex;
    if(n == 5)
        ft_printf("Infile: Failed to open the file!\n");
    exit(EXIT_FAILURE);
}