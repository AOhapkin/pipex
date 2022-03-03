#include "pipex.h"

char    *get_command_path(char *command_name, char **envp)
{
    char    *full_command_path;
    char    *envp_pointer;
    char    *path;
    int     path_len;
    int     i;

    i = 0;
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
        i++;
    if (!envp[i])
        return (command_name);
    envp_pointer = envp[i] + 5;
    path_len = ft_len_to_char(envp_pointer, ':');
    while (envp_pointer && path_len >= 0)
    {
        path_len = ft_len_to_char(envp_pointer, ':');
        path = ft_strndub(envp_pointer, path_len);
        full_command_path = ft_join_path_and_name(path, command_name);
        free(path);
        if (access(full_command_path, F_OK))
            return (full_command_path);
        free(full_command_path);
        envp_pointer += ft_len_to_char(envp_pointer, ':') + 1;
    }
    return (command_name);
}

void    run_child_process(char **argv, char **envp, int fd[2])
{
    int     first_file;
    char    **command;
    char    *command_path;

//    first_file = open_infile(argv[1]);
//    if (first_file < 0)
//        error_exit();
//    dup2(first_file, 0);
//    dup2(fd[1], 1);
//    close(fd[0]);
//    command = ft_split(argv[2], SPACE);
//    command_path = get_commadn_path(argv[0]);

}

void    run_parent_process(char **argv, char **envp, int fd[2])
{

}

int	main(int argc, char **argv, char **envp)
{
	int     fd[2];
    pid_t   process_id;
	
	if (argc == 5)
	{
        if (pipe(fd) == -1)
            error_exit();
        process_id = fork();
        if (process_id == -1)
            error_exit();
        else if (process_id == 0)
            run_child_process(argv, envp, fd);
        else
            run_parent_process(argv, envp, fd);
	}
    else
        ft_putendl_fd("Error! Must be 4 arguments.", 2);
	return (0);
}
