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

