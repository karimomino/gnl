/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@42abudhabi.ae>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 03:38:23 by kamin             #+#    #+#             */
/*   Updated: 2021/10/19 05:21:10 by kamin            ###   ########.fr       */
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
	if (*file_content == NULL)
		return (NULL);
	if(ft_strchr(*file_content, '\n') || ft_strchr(*file_content, '\0'))
	{
		while ((*file_content)[i] != '\n' || (*file_content)[i] != '\0')
			i++;
	}
	else
		return (NULL);
	ret = ft_substr(*file_content, 0, i - 1);
	*file_content += i;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	char		*tmp;
	static char *file_content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, buff, BUFFER_SIZE) > 0)
	{
		if (file_content == NULL)
			file_content = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(file_content, buff);
			free(file_content);
			file_content = tmp;
			free(tmp);
		}
	}
	return (ft_line(&file_content));
}

int main()
{
	char *x;
	int fd = open("empty_file", O_RDONLY);
	x = get_next_line(fd);
	printf("%s", x);
	// while (x)
	// {
	// 	printf("%s", x);
	// 	x = get_next_line(fd);
	// }
	return 0;
}
