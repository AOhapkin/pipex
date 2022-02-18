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
	int	fd[2];
	
	if (argc == 5)
	{
		/* code */
	}
	return (0);
}