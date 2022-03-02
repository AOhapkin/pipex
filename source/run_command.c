#include "pipex.h"

char *find_command_path(char *command, char **envp)
{
    char    *full_path;
    char    *temp;
}

void    run_command(char *argv, char **envp)
{
    char    **command;
    char    *command_path;
    int     i;

    command = ft_split(argv, SPACE);
    command_path = find_command_path(command[0], envp);
    i = 0;
    if (!command_path)
    {
        while (command[i])
        {
            free(command[i]);
            i++;
        }
        free(command);
        error_exit();
    }
    if (execve(command_path, command, envp) == -1)
        error_exit();
}