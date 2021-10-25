#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*destination;
	char	*buff;
	size_t	i;

	buff = (char *)malloc(len * sizeof(char));
	if (!buff)
		return (NULL);
	source = (char *)src;
	destination = (char *)dst;
	i = 0;
	if ((dst == NULL && src == NULL) && len > 0)
		return (NULL);
	while (i++ < len)
	{
		buff[i - 1] = source[i - 1];
	}
	i = 0;
	while (i++ < len)
	{
		destination[i - 1] = buff[i - 1];
	}
	free(buff);
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int		len;
	char	*string;

	len = ft_strlen(s) + 1;
	string = (char *)s;
	if (c > 127 || c < 0)
		return (string);
	while (len-- > 0)
	{
		if (*string == c)
			return (string);
		string++;
	}
	return (NULL);
}

char	*ft_line(char **file_content)
{
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	if (*file_content == NULL || **file_content == '\0')
		return (NULL);
	while ((*file_content)[i] != '\0' && (*file_content)[i] != '\n')
		i++;
	if ((*file_content)[i] == '\n')
		i++;
	ret = ft_substr(*file_content, 0, i);
	temp = *file_content + i;
	ft_memmove(*file_content, temp, ft_strlen(temp) + 1);
	return (ret);
}

int	ft_read_file_content(int fd, char **file_content)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			read_val;

	buff[0] = '\0';
	read_val = 1;
	while (ft_strchr(buff, '\n') == NULL && read_val > 0)
	{
		read_val = read(fd, buff, BUFFER_SIZE);
		if (read_val < 0)
			return (0);
		buff[read_val] = '\0';
		if (*file_content == NULL && read_val > 0)
			*file_content = ft_strdup(buff);
		else if (read_val > 0)
		{
			tmp = ft_strjoin(*file_content, buff);
			free(*file_content);
			*file_content = ft_strdup(tmp);
			free(tmp);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*file_content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_file_content(fd, &file_content);
	return (ft_line(&file_content));
}
