/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:51:39 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/15 09:51:49 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_command(char *command, char **envp)
{
	char	**paths;
	char	*temp;
	char	*full_path;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) && envp[i] != NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, command);
		free(temp);
		if (!access(full_path, F_OK))
		{
			free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free(paths);
	return (NULL);
}

void	run_child_process(char **argv, char **envp, int *fd)
{
	int		infile_fd;
	char	**args_vector;
	char	*file_path;

	ft_dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	file_path = ft_get_file_path(argv[1], 1, envp);
	infile_fd = open(file_path, O_RDONLY);
	free(file_path);
	if (infile_fd == -1)
		ft_error_exit("Infile error");
	ft_dup2(infile_fd, 0);
	args_vector = ft_split(argv[2], ' ');
	execve(ft_get_command(args_vector[0], envp), args_vector, envp);
}

void	run_parent_process(char **argv, char **envp, int *fd)
{
	int		outfile_fd;
	char	**command_args;
	char	*file_path;

	file_path = ft_get_file_path(argv[4], 0, envp);
	outfile_fd = open(file_path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	free(file_path);
	if (outfile_fd == -1)
		ft_error_exit("can't open or create outfile_fd");
	ft_dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	ft_dup2(outfile_fd, 1);
	command_args = ft_split(argv[3], ' ');
	execve(ft_get_command(command_args[0], envp), command_args, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error_exit("pipe error");
		pid1 = ft_fork();
		if (pid1 == 0)
			run_child_process(argv, envp, fd);
		pid2 = ft_fork();
		if (pid2 == 0)
			run_parent_process(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		ft_error_exit("Error! Pipex need 4 arguments");
	return (0);
}
