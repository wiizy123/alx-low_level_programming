#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
    char *buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        perror("Error: Cannot allocate memory for buffer");
        exit(EXIT_FAILURE);
    }

    return buffer;
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
    if (close(fd) == -1)
    {
        perror("Error: Cannot close file descriptor");
        exit(EXIT_FAILURE);
    }
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
    int from, to, r, w;
    char *buffer;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        exit(EXIT_FAILURE);
    }

    from = open(argv[1], O_RDONLY);

    if (from == -1)
    {
        perror("Error: Cannot open file for reading");
        exit(EXIT_FAILURE);
    }

    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    if (to == -1)
    {
        perror("Error: Cannot open file for writing");
        close_file(from);
        exit(EXIT_FAILURE);
    }

    buffer = create_buffer();

    do
    {
        r = read(from, buffer, 1024);

        if (r == -1)
        {
            perror("Error: Cannot read from file");
            free(buffer);
            close_file(from);
            close_file(to);
            exit(EXIT_FAILURE);
        }

        w = write(to, buffer, r);

        if (w == -1)
        {
            perror("Error: Cannot write to file");
            free(buffer);
            close_file(from);
            close_file(to);
            exit(EXIT_FAILURE);
        }

    } while (r > 0);

    free(buffer);
    close_file(from);
    close_file(to);

    return (EXIT_SUCCESS);
}
