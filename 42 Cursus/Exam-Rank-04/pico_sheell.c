#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>



int picoshell(char **cmds[])
{
	int fd[2];
	pid_t pid;


	int out;
	int in = -1;
	int i = 0;



	while (cmds[i])
	{
		out = cmds[ i + 1] != NULL;
		if(out)
			pipe(fd);
		pid = fork();

		if (pid == 0)
		{
			if(out)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			if (in != -1)
			{
				dup2(in, STDIN_FILENO);
				close(in);
			}

			execvp(cmds[i][0],cmds[i]);
			exit(1);
		}
		if (in != -1)
			close(in);
		if(out)
		{
			close(fd[1]);
			in = fd[0];
		}
		i++;
	}

	while (i--)
		wait(NULL);
	return(0);
}
