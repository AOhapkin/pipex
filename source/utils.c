#include "pipex.h"

void    error_exit(char *error_message)
{
    perror(error_message);
    exit(0);
}

void	ft_putchar_fd(char c, int fd)
{
    write (fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
    if (!s)
        return ;
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
    ft_putchar_fd('\n', fd);
}

int	open_infile(char *file_name)
{
    if (access(file_name, F_OK) < 0)
    {
        write(2, "File not found\n", 15);
        exit(EXIT_FAILURE);
    }
    return (open(file_name, O_RDONLY));
}

int	open_outfile(char *file_name)
{
    if (access(file_name, F_OK) < 0)
    {
        write(2, "File not found\n", 15);
        exit(EXIT_FAILURE);
    }
    return (open(file_name, O_CREAT | O_WRONLY | O_TRUNC));
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