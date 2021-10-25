#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*DELETE BELOW*/
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
/*DELETE ABOVE*/
#include <unistd.h>
 #include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_line(char **file_content);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
#endif
