#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int fd_from, fd_to, nread;
    char buffer[BUFSIZE];

    if (argc != 3) {
        printf("Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        printf("Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_to == -1) {
        printf("Error: Can't write to %s\n", argv[2]);
        exit(99);
    }

    while ((nread = read(fd_from, buffer, BUFSIZE)) > 0) {
        if (write(fd_to, buffer, nread) != nread) {
            printf("Error: Can't write to %s\n", argv[2]);
            exit(99);
        }
    }

    if (nread == -1) {
        printf("Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    if (close(fd_from) == -1 || close(fd_to) == -1) {
        printf("Error: Can't close file descriptors\n");
        exit(100);
    }

    return 0;
}
