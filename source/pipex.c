#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int     fd[2];
    pid_t   process_id;
	
	if (argc == 5)
	{
        if (pipe(fd) != 0)
            error_exit();
        process_id = fork();
        if (process_id == -1)
            error_exit();
        else if (process_id == 0)
            child_processing(argv, envp, fd);
        waitpid(process_id, NULL, 0);
        parent_processing(argv, envp, fd);
	}
    else
        ft_putendl_fd("Error! Must be 4 arguments.", 2);
	return (0);
}