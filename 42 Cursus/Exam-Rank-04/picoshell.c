#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int picoshell(char **cmds[])
{
    int i = 0;
    int fd[2];
    int in_fd = -1;
    pid_t pid;
    while (cmds[i])
    {
        int has_next = (cmds[i + 1] != NULL);
        if (has_next)
        {
            if (pipe(fd) == -1)
            {
                if (in_fd != -1)
                    close(in_fd);
                return 1;
            }
        }
        pid = fork();
        if (pid < 0)
        {
            if (in_fd != -1)
                close(in_fd);
            if (has_next)
            {
                close(fd[0]);
                close(fd[1]);
            }
            return 1;
        }
        else if (pid == 0)
        {
            if (in_fd != -1)
            {
                if (dup2(in_fd, 0) == -1)
                    exit(1);
            }
            if (has_next)
            {
                if (dup2(fd[1], 1) == -1)
                    exit(1);
            }
            if (in_fd != -1)
                close(in_fd);
            if (has_next)
            {
                close(fd[0]);
                close(fd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        else
        {
            if (in_fd != -1)
                close(in_fd);
            if (has_next)
            {
                close(fd[1]);
                in_fd = fd[0];
            }
        }
        i++;
    }
    for (int j = 0; j < i; j++)
        wait(NULL);
    return 0;
}

int main(int argc, char **argv)
{
    // Test 1: Single command - ls -l
    printf("Test 1: ls -l\n");
    char *cmd1[] = {"ls", "-l", NULL};
    char **cmds1[] = {cmd1, NULL};
    picoshell(cmds1);
    printf("\n");

    // Test 2: Two commands piped - ls | wc -l
    printf("Test 2: ls | wc -l\n");
    char *cmd2a[] = {"ls", NULL};
    char *cmd2b[] = {"wc", "-l", NULL};
    char **cmds2[] = {cmd2a, cmd2b, NULL};
    picoshell(cmds2);
    printf("\n");

    // Test 3: Three commands piped - cat /etc/passwd | grep root | wc -l
    printf("Test 3: cat /etc/passwd | grep root | wc -l\n");
    char *cmd3a[] = {"cat", "/etc/passwd", NULL};
    char *cmd3b[] = {"grep", "root", NULL};
    char *cmd3c[] = {"wc", "-l", NULL};
    char **cmds3[] = {cmd3a, cmd3b, cmd3c, NULL};
    picoshell(cmds3);
    printf("\n");

    // Test 4: Echo and grep - echo hello world | grep world
    printf("Test 4: echo hello world | grep world\n");
    char *cmd4a[] = {"echo", "hello", "world", NULL};
    char *cmd4b[] = {"grep", "world", NULL};
    char **cmds4[] = {cmd4a, cmd4b, NULL};
    picoshell(cmds4);
    printf("\n");

    // Test 5: More complex pipeline - ls -la | grep "^d" | wc -l
    printf("Test 5: ls -la | grep \"^d\" | wc -l (count directories)\n");
    char *cmd5a[] = {"ls", "-la", NULL};
    char *cmd5b[] = {"grep", "^d", NULL};
    char *cmd5c[] = {"wc", "-l", NULL};
    char **cmds5[] = {cmd5a, cmd5b, cmd5c, NULL};
    picoshell(cmds5);

    return 0;
}