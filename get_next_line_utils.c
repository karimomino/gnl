#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	joined = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (joined == NULL || !s1 || !s2)
		return (NULL);
	while (s1[++i] != '\0')
	{
		*joined = s1[i];
		joined++;
	}
	i = -1;
	while (s2[++i])
	{
		*joined = s2[i];
		joined++;
	}
	*joined = '\0';
	joined -= (len1 + len2);
	return (joined);
}

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (size);
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, len);
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	counter;
	unsigned int	tried;

	counter = 0;
	tried = 0;
	while (src[tried] != '\0')
		tried++;
	if (size > 0)
	{
		while (*src != 0 && counter < size - 1)
		{
			*dst = *src;
			dst++;
			src++;
			counter++;
		}
		*dst = '\0';
	}
	return (tried);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start > ft_strlen(s))
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) || len > ((size_t)ft_strlen(s) - (size_t)start))
		len = (size_t)ft_strlen(s) - (size_t)start;
	sub = (char *)malloc((1 + len) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, (s + start), len + 1);
	return (sub);
}
