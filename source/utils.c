#include "pipex.h"

void    error_exit(void)
{
    perror("Program exit with error");
    exit(EXIT_FAILURE);
}