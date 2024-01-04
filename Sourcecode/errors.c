#include "../Inc/pipex.h"

void    ft_errors2(t_pipex *pipex, int n)
{
    if(n == 5)
        ft_putstr_fd("Error!\ndup2() function has failed!\n", STDERR_FILENO);
    if(n == 5)
        ft_free_all(pipex, 1);
    if(n == 6)
        ft_putstr_fd("Error!\nChild split() function has failed!\n", STDERR_FILENO);
    if(n == 6)
        ft_free_all(pipex, 1);
    if(n == 7)
        ft_putstr_fd("Error!\nFirst ft_strjoin_free function has failed!\n", STDERR_FILENO);
    if(n == 8)
        ft_putstr_fd("Error!\nSecond ft_strjoin_free function has failed!\n", STDERR_FILENO);
    if(n == 7 || n == 8)
        ft_free_all(pipex, 2);
    if(n == 9)
        ft_free_all(pipex, 3);
    if(n == 10)
        ft_putstr_fd("Error!\nCommand not found!\n", STDERR_FILENO);
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
        ft_putstr_fd("Error!\nParent split() function has failed!\n", STDERR_FILENO);
    if (n == 1)
        exit(EXIT_FAILURE);
    if (n == 2)
        ft_putstr_fd("Error! pipe() function failed!\n", STDERR_FILENO);
    if (n == 2)
        ft_free_all(pipex, 1);
    if (n == 3)
        ft_putstr_fd("Error! fork() function failed!\n", STDERR_FILENO);
    if (n == 3)
        ft_free_all(pipex, 1);
    if (n == 4)
        ft_putstr_fd("Error!\nInfile: Failed to open the file!\n", STDERR_FILENO);
    if (n == 4)
        ft_free_all(pipex, 1);
    ft_errors2(pipex, n);
}