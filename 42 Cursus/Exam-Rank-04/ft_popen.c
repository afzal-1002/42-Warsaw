#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int	ft_popen(char *file, char *const argv[], char type)
{
	int		fd[2];
	pid_t	pid;

	if (!file || !argv || (type != 'r' && type != 'w') || pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (dup2(type == 'r' ? fd[1] : fd[0], type == 'r' ? STDOUT_FILENO : STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(fd[0]);
		close(fd[1]);
		execv(file, argv);
		exit(EXIT_FAILURE);
	}
	close(type == 'r' ? fd[1] : fd[0]);
	return (type == 'r' ? fd[0] : fd[1]);
	
}
