#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define SPACE  ' '

void    error_exit(void);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char *string, char divider);
int     open_infile(char *file_name);
int     open_outfile(char *file_name);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_len_to_char(char *string, char c);

#endif