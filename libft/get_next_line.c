#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static  void *ft_free(char **ptr, char *newbuffer)
 {
 	if (ptr && *ptr)
 	{
 		free(*ptr);
 		*ptr = newbuffer;
 	}
 	return (NULL); 
}

static char *ft_read(int fd, char *buffer)
{
    char temp[BUFFER_SIZE + 1];
    int bytes_read;
    char *new_buffer;

    while (!ft_strchr(buffer, '\n'))
    {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read < 0)
            return (ft_free(&buffer, NULL));
        if (bytes_read == 0)
            break;
        temp[bytes_read] = '\0';
        new_buffer = ft_strjoin(buffer, temp);
        if (!new_buffer)
            return (ft_free(&buffer, NULL));
        free(buffer);
        buffer = new_buffer;
    }
    return (buffer);
}

static char *return_line(char **buffer)
{
    char *line;
    char *newline;
    char *temp;

    newline = ft_strchr(*buffer, '\n');
    if (newline)
    {
        *newline = '\0';
        line = ft_strjoin(*buffer, "\n");
        if (!line)
            return (ft_free(buffer, NULL));
        temp = ft_strdup(newline + 1);
        if (!temp)
        {
            free(line);
            return (ft_free(buffer, NULL));
        }
        free(*buffer);
        *buffer = temp;
    }
    else
    {
        line = ft_strdup(*buffer);
        ft_free(buffer, NULL);
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!buffer)
    {
        buffer = ft_strdup("");
        if (!buffer)
            return (NULL);
    }
    buffer = ft_read(fd, buffer);
    if (!buffer)
        return (NULL);
    if (!*buffer)
        return (ft_free(&buffer, NULL));
    
    return (return_line(&buffer));
}
/*
int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
    	fd = 0;
    }
    else
    {	
    	fd = open(argv[1], O_RDONLY);
    	if (fd == -1)
    	{
        	perror("Error opening file");
        	return 1;
    	}
    }
    int line_count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s\n", ++line_count, line);
        free(line);  // Don't forget to free the allocated memory
    }

    close(fd);
    printf("Total lines read: %d\n", line_count);

    return 0;
}*/
