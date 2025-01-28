#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t destsize)
{
	size_t	i;

	if (!src || destsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if(!s2)
		return (NULL);
	s1len = ft_strlen(s1);	
	s2len = ft_strlen(s2);
	s3 = (char *)malloc(s1len + s2len + 1);
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, s1len + 1);
	ft_strlcpy(s3 + s1len, s2, s2len + 1);
	free(s1);
	return (s3);
}

char	*ft_strdup(char *str)
{
	char	*str_cpy;
	size_t	i;

	if (!str)
		return(NULL);
	str_cpy = malloc(ft_strlen(str) + 1);
	if (!str_cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	if (!str)
		return(NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;	
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
