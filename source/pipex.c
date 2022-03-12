#include "pipex.h"

char    *ft_get_command(char *command, char **envp)
{
    char	**paths;
    char	*temp;
    char	*full_path;
    int		i;

    i = 0;
    while (ft_strncmp(envp[i], "PATH", 4) && envp[i] != NULL)
        i++;
    paths = ft_split(envp[i] + 5, ':');
    i = 0;
    while (paths[i] != NULL)
    {
        temp = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(temp, command);
        free(temp);
        if (!access(full_path, F_OK))
        {
            free(paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    free(paths);
    return (NULL);
}

void    run_child_process(char **argv, char **envp, int *fd)
{
    int		infile;
    char	**argVec1;
    char	*file_path;

    ft_dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
    file_path = ft_get_file_path(envp, argv[1], 1);
    infile = open(file_path, O_RDONLY);
    free(file_path);
    if (infile == -1)
        ft_error_exit("can't open infile");
    ft_dup2(infile, 0);
    argVec1 = ft_split(argv[2], ' ');
    execve(ft_get_command(envp, argVec1[0]), argVec1, envp);
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
            run_child_process(argv, envp, fd);
        pid2 = ft_fork();
        if (pid2 == 0)
            run_parent_process(argv, envp, fd);
        close(fd[0]);
        close(fd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    }
    ft_error_exit("Error! Must be 4 arguments");
	return (0);
}
