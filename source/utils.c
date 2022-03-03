#include "pipex.h"

void    error_exit(void)
{
    perror("Program exit with error");
    exit(EXIT_FAILURE);
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

int ft_len_to_char(char *string, char c)
{
    int len;

    len = 0;
    while (string[len] && string[len] != c)
        len++;
    if (string[len] == c)
        return (len);
    else
        return (-1);
}

char    *ft_strndub(const char *string, unsigned int n)
{
    int     i;
    char    *new_string;

    new_string = malloc(sizeof(char) * (n + 1));
    if (!new_string)
        return (NULL);
    i = 0;
    while (i < n)
    {
        new_string[i] = string[i];
        i++;
    }
    new_string[i] = '\0';
    return (new_string);
}
