#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - Creates a file with specified content
 * @filename: Name of file to create
 * @text_content: Content to write to file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len, bytes_written;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	len = strlen(text_content);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	bytes_written = write(fd, text_content, len);
	if (bytes_written == -1 || bytes_written != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
