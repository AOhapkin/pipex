#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	**ft_split(char *string, char divider);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void    ft_error_exit(char *error_message);
pid_t	ft_fork(void);
int     ft_dup2(int old, int new);
char	*ft_get_file_path(char *filename, int filecheck, char **envp);

#endif