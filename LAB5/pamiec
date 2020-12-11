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
        fd_mem = open("pamiec", O_RDWR);
        if (fd_mem < 0)
        {
            fd_mem = open("pamiec", O_CREAT | O_RDWR);
        }
        size = lseek(fd, 0, SEEK_END);
        ftruncate(fd_mem, size);
        lseek(fd, 0, SEEK_SET);
        addres = (int *)mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd_mem, 0);
        read(fd, addres, size);
        msync(addres, size, MS_ASYNC);
        close(fd);
        close(fd_mem);
    }
    return 0;
}