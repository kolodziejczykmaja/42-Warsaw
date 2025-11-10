#include "get_next_line.h"
#include <stdio.h>


char *change_buffer(char *buffer, ssize_t i)
{
	char *tmp;
	ssize_t size_buffer;
	ssize_t j;

	if (i == -1 || !buffer || i == ft_strlen(buffer)) 
	{
		buffer = NULL;
		return (buffer);
	}
	j = 0;
	size_buffer = ft_strlen(buffer);
	tmp = malloc(sizeof(char) * (size_buffer - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	while (i < size_buffer)
		tmp[j++] = buffer[i++];
	tmp[j] = '\0';
	//free(buffer);
	buffer = NULL;
	return (tmp);
}

char *line_in_buffer(char *buffer)
{
	char *line;
	ssize_t i;
	ssize_t j;

	if (!buffer)
		return (NULL);
	i = is_endl_in_buffer(buffer);
	j = 0;
	if (buffer && (is_endl_in_buffer(buffer) != -1))
	{
		i = is_endl_in_buffer(buffer);
		line = malloc(sizeof(char) * (i + 1));
		if (!line)
			return (NULL);
		while (j < i)
		{
			line[j] = buffer[j];
			j++;
		}
		line[j] = '\0';
		return (line);
	}
	// if (buffer && (is_endl_in_buffer(buffer) == -1))
	// {
	// 	line = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	// 	if (!line)
	// 		return (NULL);
	// 	while (j < ft_strlen(buffer))
	// 	{
	// 		line[j] = buffer[j];
	// 		j++;
	// 	}
	// 	line[j] = '\0';
	// 	return (line);
	// }
	return (NULL);
}

ssize_t is_endl_in_buffer(char *buffer)
{
	int i;

	i = 0;
	if (!buffer)
		return (-1);
	while (i < ft_strlen(buffer))
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *read_buffer(int fd, ssize_t *flag)
{
	char *buffer;
	ssize_t i;

		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = read (fd, buffer, BUFFER_SIZE);
	if (i < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (i == 0)
	{
		free(buffer);
		*flag = 0;
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

char *read_line(char *buffer, int fd)
{
	ssize_t flag;
	char *r;

	r = NULL;
	flag = 1;
	while(flag != 0 && is_endl_in_buffer(buffer) == -1 && (r = read_buffer(fd, &flag)))
	{
		buffer = ft_strjoin(buffer, r);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (!buffer) {
    buffer = malloc(1);
    if (!buffer)
        return (NULL);
    buffer[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer = read_line(buffer, fd);
	line = line_in_buffer(buffer);
	buffer = change_buffer(buffer, is_endl_in_buffer(buffer));
	if (line)
		return (line);
	return (NULL);
}

// #include <fcntl.h>

// int main () {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY); 
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	// line = get_next_line(fd);
// 	// printf("%s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("%s\n", line);		
// 	// line = get_next_line(fd);
// 	// printf("%s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("%s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("%s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("%s\n", line);
    
//     close(fd);
// 	return (0);
// }
