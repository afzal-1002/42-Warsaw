#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	picoshell(char **cmds[])
{
	pid_t	pid;
	int		next;

	int fd[2], in = -1, i = 0;
	while (cmds[i])
	{
		next = cmds[i + 1] != NULL;
		if (next)
			pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			if (in != -1)
			{
				dup2(in, STDIN_FILENO);
				close(in);
			}
			if (next)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in != -1)
			close(in);
		if (next)
		{
			close(fd[1]);
			in = fd[0];
		}
		i++;
	}
	while (i--)
		wait(NULL);
	return (0);
}
