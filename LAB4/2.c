#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    int fd[2];
    pipe(fd);
    int id = fork();
    if (id > 0)
    {
        close(fd[0]);
        char *message = "Podaj nazwe pliku:\n";
        write(STDOUT_FILENO, message, strlen(message));
        char buffer[255];
        int bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer));
        buffer[bytesRead - 1] = '\0'; // usuniecie '\n' ze stringa
        int image_fd = open(buffer, O_RDONLY);
        if (image_fd < 0)
        {
            message = "Blad otwarcia pliku\n";
            write(STDOUT_FILENO, message, strlen(message));
            write(STDOUT_FILENO, strerror(errno), strlen(strerror(errno)));
            write(STDOUT_FILENO, "\n", 1);
            return -1;
        }
        int *buff2;
        while (read(image_fd, &buff2, 1) > 0)
        {
            write(fd[1], &buff2, 1);
        }
        close(fd[1]);
        return 0;
    }
    else if (id == 0)
    {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        execlp("/usr/bin/display", "display", (char *)NULL);
        close(fd[0]);
        exit(1);
    }
    else
    {
        char *message = "Blad w funkcji fork";
        write(1, message, strlen(message));
        return -1;
    }
}
