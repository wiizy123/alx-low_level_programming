#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/uio.h>

/**
 * read_textfile - A function that reads a text file and prints
 * to the POSIX STDOUT
 * @filename: The filename to open
 * @letters: The number of letters to read and print
 * Return: The number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t bytes_read, bytes_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(buffer);
        return (0);
    }

    bytes_read = read(fd, buffer, letters);
    if (bytes_read < 0)
    {
        free(buffer);
        return (0);
    }

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    free(buffer);
    close(fd);

    if (bytes_written < 0)
        return (0);

    return((ssize_t)bytes_written);
}
