#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char *FIFOname = "exFIFO";
    if (argc == 1)
    {
        char *message = "Brak argumentu\n";
        write(STDOUT_FILENO, message, strlen(message));
        return -1;
    }
    mkfifo(FIFOname, 0666);
    int fd = open(FIFOname, O_WRONLY);
    int buffer[1];
    for (int i = 1; i < argc; i++)
    {
        int file_fd = open(argv[i], O_RDONLY);
        while (read(file_fd, buffer, 1) > 0)
        {
            write(fd, buffer, strlen(buffer));
        }
        close(file_fd);
        printf("wyslalem plik nr %d\n", i);
        sleep(5);
    }
    close(fd);
    return 0;
}
