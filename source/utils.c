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
    i = 0;
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

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0)
    {
        if (*s1 != *s2)
            return (*(unsigned char *)s1 - *(unsigned char *)s2);
        if (*s1 == '\0')
            break ;
        s1++;
        s2++;
        n--;
    }
    return (0);
}

int ft_strlen(const char *string)
{
    int len;

    len = 0;
    while (*string)
    {
        len++;
        string++;
    }
    return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*dest;
    int		dest_len;
    int		i;
    int		j;

    if (!s1 || !s2)
        return (NULL);
    dest_len = ft_strlen(s1) + ft_strlen(s2) + 1;
    dest = malloc(sizeof(char) * dest_len);
    if (!dest)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        dest[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i])
        dest[j++] = s2[i++];
    dest[j] = '\0';
    return (dest);
}
