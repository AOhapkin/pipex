int	open_infile(char *file_name)
{
	if (access(file_name, F_OK) < 0)
	{
		write(2, "File not found\n", 15);
		return (0);
	}
	return (open(file_name, O_RDONLY));
}

int	open_outfile(char *file_name)
{
	if (access(file_name, F_OK) < 0)
	{
		write(2, "File not found\n", 15);
		return (0);
	}
	return (open(file, O_CREAT | O_WRONLY | O_TRUNC));
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_infile;
	int	fd_outfile;
	
	if (argc == 5)
	{
		fd_infile = open_infile(argv[1]);
		fd_outfile = open_outfile(argv[4]);
		dup2(fd_infile, 0);
		dup2(fd_outfile, 1);
	}
	return (0);
}