#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int ft_popen(char *file, char *const argv[], char type);

int main(void)
{
    int fd;
    char buf[128];
    ssize_t n;

    char *args_r[] = {"/bin/echo", "hello from child", NULL};
    fd = ft_popen("/bin/echo", args_r, 'r');
    if (fd == -1)
    {
        perror("ft_popen r");
        return 1;
    }
    n = read(fd, buf, sizeof(buf) - 1);
    if (n > 0)
    {
        buf[n] = '\0';
        printf("read: %s", buf);
    }
    close(fd);

    char *args_w[] = {"/bin/cat", NULL};
    fd = ft_popen("/bin/cat", args_w, 'w');
    if (fd == -1)
    {
        perror("ft_popen w");
        return 1;
    }
    write(fd, "hello to child\n", 15);
    close(fd);

    return 0;
}
