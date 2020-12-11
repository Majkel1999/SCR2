#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    char fileName[100];
    int fd, fd_mem, size;
    int *addres = NULL;
    int fork_no = fork();
    fd_mem = open("obrazek.png", O_RDWR);
    if (fd_mem < 0)
    {
        fd_mem = open("obrazek.png", O_CREAT | O_RDWR);
    }
    if (fork_no == -1)
    {
        exit(-1);
    }
    if (fork_no == 0)
    {
        execlp("qiv", "qiv", "--watch", "obrazek.png", (char *)NULL);
    }
    else if (fork_no > 0)
    {
        while (1)
        {
            printf("Podaj nazwe pliku: ");
            scanf("%s", fileName);
            fd = open(fileName, O_RDWR);
            while (fd < 0)
            {
                printf("Niepoprawny plik.\nPodaj nazwe pliku: ");
                scanf("%s", fileName);
                fd = open(fileName, O_RDWR);
            }
            size = lseek(fd, 0, SEEK_END);
            lseek(fd, 0, SEEK_SET);
            ftruncate(fd_mem, size);
            addres = (int *)mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd_mem, 0);
            read(fd, addres, size);
            msync(addres, size, MS_SYNC);
            close(fd);
            munmap(addres, size);
        }
    }
    close(fd_mem);
    return 0;
}