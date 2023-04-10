#include <stdio.h>
#include <stdlib.h>

/**
 * read_file - reads a file and prints its contents to the console
 * @filename: name of the file to read
 * @max_chars: maximum number of characters to read
 *
 * Return: number of characters read, or 0 on error
 */
ssize_t read_file(const char *filename, size_t max_chars)
{
    int fd;
    ssize_t n_bytes_read, n_bytes_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * max_chars);
    if (buffer == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buffer);
        return (0);
    }

    n_bytes_read = read(fd, buffer, max_chars);
    if (n_bytes_read == -1)
    {
        free(buffer);
        return (0);
    }

    n_bytes_written = write(STDOUT_FILENO, buffer, n_bytes_read);
    free(buffer);
    close(fd);

    if (n_bytes_written == -1)
        return (0);

    return (n_bytes_read);
}


