#include "pipex.h"

char *get_command_path(char *comand, char **envp)
{
    int     i;
    char    **all_paths;
    char    *temp;
    char    *full_path;

    i = 0;
    while (ft_strncmp(envp[i], "PATH=", 5) == 0)
        i++;
    all_paths = ft_split((envp[i] + 5), ':');
    i = 0;
    while (all_paths[i])
    {
        temp = ft_strjoin(all_paths[i], "/");
        full_path = ft_strjoin(temp, comand);
        free(temp);
        if (access(full_path, F_OK) == 0)
        {
            i = 0;
            while (all_paths[i])
                free(all_paths[i]);
            free(all_paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    i = -1;
    while (all_paths[++i])
        free(all_paths[i]);
    free(all_paths);
    return (0);
}

void    run_command(char *argv, char **envp)
{
    char	**command_w_flags;
    char	*path;
    int 	i;

    command_w_flags = ft_split(argv, SPACE);
    path = get_command_path(command_w_flags[0], envp);
    i = 0;
    if (!path)
    {
        while (command_w_flags[i])
        {
            free(command_w_flags[i]);
            i++;
        }
        free(command_w_flags);
        ft_error_exit("Command not found");
    }
    command_w_flags++;
    if (execve(path, command_w_flags, envp) == -1)
        ft_error_exit("Command error");
}

void    run_child_process(char **argv, char **envp, int fd)
{
    int     first_file;

    first_file = ft_open_infile(argv[1]);
    dup2(fd, 1);
    dup2(first_file, 0);
    close(fd);
    run_command(argv[2], envp);
}

void    run_parent_process(char **argv, char **envp, int fd)
{
    int second_file;

    second_file = ft_open_outfile(argv[4]);
    dup2(fd, 0);
    dup2(second_file, 1);
    close(fd);
    run_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int     fd[2];
    pid_t   pid1;
    pid_t   pid2;

	if (argc == 5)
	{
        if (pipe(fd) == -1)
            ft_error_exit("pipe error");
        pid1 = ft_fork();
        if (pid1 == 0)
            run_child_process(argv, envp, fd[0]);
        pid2 = ft_fork();
        if (pid2 == 0)
            run_parent_process(argv, envp, fd[1]);
        close(fd[0]);
        close(fd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    }
    ft_error_exit("Error! Must be 4 arguments");
	return (0);
}
