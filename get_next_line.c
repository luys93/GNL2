#include "get_next_line.h"

char	*ft_extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 2);
	return (line);
}

char	*ft_readline(int fd, char *buffer)
{
	char	*remainder;
	ssize_t	b_read;

	remainder = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!remainder)
		return (NULL);
	b_read = 1;	
	while (b_read > 0)
	{
		b_read = read(fd, remainder, BUFFER_SIZE);
		if (b_read == -1)
		{
			perror("Errore lettura file\n"); 
			free(remainder);
			return (NULL);
		}
		remainder[b_read] = '\0';
		buffer = ft_strjoin(buffer, remainder);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(remainder);
	return(buffer);
}

char	*ft_stock_rest(char *buffer)
{
	char	*rest;
	char	*char_pos;

	char_pos = ft_strchr(buffer, '\n');
	if (!char_pos)	
	{
		free(buffer);
		return(NULL);
	}		
	rest = ft_strdup(char_pos + 1);
	free(buffer);
	if (!rest[0])
	{
		free(rest);
		return (NULL);
	}
	return(rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);	
	buffer = ft_readline(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_stock_rest(buffer);

	return (line);
}

/*int	main(void)
{
    int fd = open("test2.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Errore nell'apertura del file");
        return (1);
    }

    char *line;
    size_t i = 1;

    while (i < 20)
    {
		line = get_next_line(fd);
        printf("line[%02zu]: %s |\n", i, line);
		i++;
        free(line);
    }

    close(fd);
    return (0);
}*/