/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@42abudhabi.ae>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:55:24 by kamin             #+#    #+#             */
/*   Updated: 2021/10/26 03:08:46 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (*file_content == NULL)
		return (NULL);
	if (**file_content == '\0')
	{
		free(*file_content);
		return (NULL);
	}
	while ((*file_content)[i] != '\0' && (*file_content)[i] != '\n')
		i++;
	if ((*file_content)[i] == '\n')
		i++;
	ret = ft_substr(*file_content, 0, i);
	temp = ft_strdup(*file_content + i);
	free(*file_content);
	*file_content = temp;
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
		if (read_val <= 0 && *file_content == NULL)
			return (0);
		if (read_val <= 0 && **file_content == '\0')
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
	static char	*file_content[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_file_content(fd, &file_content[fd]);
	return (ft_line(&file_content[fd]));
}
