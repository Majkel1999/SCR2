#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        char *message = "Brak argumentu lub zbyt duzo argumentow\n";
        write(STDOUT_FILENO, message, strlen(message));
        return -1;
    }
    int fd[2];
    pipe(fd);
    int id = fork();
    if (id > 0)
    {
        close(fd[0]);
        int file_fd = open(argv[1], O_RDONLY);
        int buffer[255];
        while (read(file_fd, buffer, 256) > 0)
        {
            write(fd[1], buffer, strlen(buffer));
            for (int i = 0; i < 255; i++)
            {
                buffer[i] = '\0';
            }
        }
        close(fd[1]);
        return 0;
    }
    else if (id == 0)
    {
        close(fd[1]);
        int buffer[255];
        while (read(fd[0], &buffer, 255) > 0)
        {
            write(STDOUT_FILENO, "#\0", 2);
            write(STDOUT_FILENO, buffer, 255);
            write(STDOUT_FILENO, "#\0", 2);
            for (int i = 0; i < 255; i++)
            {
                buffer[i] = '\0';
            }
        }
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
