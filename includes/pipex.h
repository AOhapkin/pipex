#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/fcntl.h>
# include <stdio.h>
# include <stdlib.h>

void    error_exit(void);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char *string, char divider);

#endif