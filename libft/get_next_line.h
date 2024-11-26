
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024  // Set the default buffer size to 1024 bytes
# endif


char	*get_next_line(int fd);
char    *ft_substr(char *s, int start, int len);
char    *ft_strjoin(char *s1, char *s2);
int  ft_strlen(const char *s);
char    *ft_strdup(char *s);
char	*ft_strcpy(char *dest, char *src);

#endif

