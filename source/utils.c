#include "pipex.h"

pid_t	ft_fork(void)
{
    pid_t	pid;

    pid = fork();
    if (pid < 0)
        ft_error_exit("fork error");
    return (pid);
}

int	ft_dup2(int old, int new)
{
    int	buf;

    buf = dup2(old, new);
    if (buf == -1)
        ft_error_exit("dup2 error");
    return (buf);
}

char	*ft_get_file_path(char *filename, int filecheck, char **envp)
{
    char	*path_part;
    char	*temp;
    char	*full_path;
    int		i;

    i = 0;
    while (ft_strncmp(envp[i], "PWD=", 4) && envp[i] != NULL)
        i++;
    path_part = envp[i] + 4;
    temp = ft_strjoin(path_part, "/");
    full_path = ft_strjoin(temp, filename);
    free(temp);
    if (!access(full_path, F_OK) || !filecheck)
        return (full_path);
    free(full_path);
    return (NULL);
}

void    ft_error_exit(char *error_message)
{
    perror(error_message);
    exit(1);
}
