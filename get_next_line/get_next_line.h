#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char *get_next_line(int fd);
ssize_t ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
ssize_t is_endl_in_buffer(char *buffer);

#endif