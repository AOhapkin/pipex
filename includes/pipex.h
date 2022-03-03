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
int     ft_len_to_char(const char *string, char c);
char    *ft_strndub(const char *string, unsigned int n);
int     ft_strlen(const char *string);
char    *ft_join_path_and_name(char *path, char *name);

#endif