/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@42abudhabi.ae>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 03:38:23 by kamin             #+#    #+#             */
/*   Updated: 2021/10/20 19:09:22 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int		i;

	i = 0;
	if (*file_content == NULL || **file_content == '\0')
		return (NULL);
	while ((*file_content)[i] != '\0')
		i++;
	ret = ft_substr(*file_content, 0, i);
	*file_content += i + 1;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*file_content;
	int			read_val;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_val = 1;
	while (ft_strchr(buff, '\n') == NULL && read_val > 0)
	{
		read_val = read(fd, buff, BUFFER_SIZE);
		if (read_val < 0)
			return (NULL);
		buff[read_val] = '\0';
		if (file_content == NULL && read_val > 0)
			file_content = ft_strdup(buff);
		else if (read_val > 0)
		{
			tmp = ft_strjoin(file_content, buff);
			free(file_content);
			file_content = tmp;
			free(tmp);
		}
	}

	return (ft_line(&file_content));
}

// int main()
// {
// 	char *x;
// 	int fd = open("nl", O_RDONLY);
// 	x = get_next_line(fd);
// 	//printf("%s", x);
// 	while (x != NULL)
// 	{
// 		printf("%s\n", x);
// 		x = get_next_line(fd);
// 	}
// 	return 0;
// }
