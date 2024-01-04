#include "../Inc/pipex.h"

void    ft_errors2(t_pipex *pipex, int n)
{
    if(n == 5)
        ft_printf("Error!\ndup2() function has failed!\n");
    if(n == 5)
        ft_free_all(pipex, 1);
    if(n == 6)
        ft_printf("Error!\nChild split() function has failed!\n");
    if(n == 6)
        ft_free_all(pipex, 1);
    if(n == 7)
        ft_printf("Error!\nFirst ft_strjoin_free function has failed!\n");
    if(n == 8)
        ft_printf("Error!\nSecond ft_strjoin_free function has failed!\n");
    if(n == 7 || n == 8)
        ft_free_all(pipex, 2);
    if(n == 9)
        ft_free_all(pipex, 3);
    if(n == 10)
        ft_printf("Error!\nCommand not found!\n");
    if(n == 10)
        ft_free_all(pipex, 3);
}

void    ft_errors(t_pipex *pipex, int n)
{
    if(n == 0)
    {
        ft_printf("Error: Wrong amount of Arguments! Expected 4!\n");
        ft_printf("Example: file1 cmd1 cmd2 file2\n");
        return ;
    }
    if (n == 1)
        ft_printf("Error!\nParent split() function has failed!\n");
    if (n == 1)
        exit(EXIT_FAILURE);
    if (n == 2)
        ft_printf("Error! pipe() function failed!\n");
    if (n == 2)
        ft_free_all(pipex, 1);
    if (n == 3)
        ft_printf("Error! fork() function failed!\n");
    if (n == 3)
        ft_free_all(pipex, 1);
    if (n == 4)
        ft_printf("Error!\nInfile: Failed to open the file!\n");
    if (n == 4)
        ft_free_all(pipex, 1);
    ft_errors2(pipex, n);
}