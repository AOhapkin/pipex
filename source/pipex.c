#include "pipex.h"

void    run_child_process(char **argv, char **envp, int fd)
{
    int     first_file;

    first_file = open_infile(argv[1]);
    dup2(fd, 1);
    dup2(first_file, 0);
    close(fd);
    get_and_run_command(argv[2], envp);
}

void    run_parent_process(char **argv, char **envp, int fd)
{
    int second_file;

    second_file = open_outfile(argv[4]);
    dup2(fd, 0);
    dup2(second_file, 1);
    close(fd);
    get_and_run_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int     fd[2];
    pid_t   process_id;
	
	if (argc == 5)
	{
        if (pipe(fd) == -1)
        {
            ft_putendl_fd("pipe error\n", 2);
            return (0);
        }
        process_id = fork();
        if (process_id == -1)
        {
            ft_putendl_fd("fork error\n", 2);
            return (0);
        }
        if (process_id == 0)
            run_child_process(argv, envp, fd[0]);
        waitpid(process_id, NULL, 0);
        run_parent_process(argv, envp, fd[1]);
	}
    ft_putendl_fd("Error! Must be 4 arguments.\n", 2);
	return (0);
}
