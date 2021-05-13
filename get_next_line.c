#include "get_next_line.h"

static void	ft_delete(char ***obj)
{
	free(**obj);
	**obj = NULL;
}

static int	ft_write_in_line(char **remainder, char **line)
{
	int		length;
	char	*tmp;

	length = ft_strlen(*remainder, '\n');
	if ((*remainder)[length] == '\n')
	{
		*line = ft_substr(*remainder, 0, length);
		tmp = ft_strdup(&(*remainder)[length + 1]);
		free(*remainder);
		*remainder = tmp;
		if (!(*remainder) || !tmp)
			ft_delete(&remainder);
	}
	else if (*remainder)
	{
		*line = ft_strdup(*remainder);
		ft_delete(&remainder);
		return (0);
	}
	return (1);
}

static int	ft_return(char **line, char **remainder, int read_bytes)
{
	if ((*remainder) && ft_strlen(*remainder, 0) && read_bytes >= 0)
		return (ft_write_in_line(remainder, line));
	ft_delete(&remainder);
	if (read_bytes < 0)
		return (-1);
	if (!*line)
	{
		*line = ft_strdup("\0");
		if (!*line)
			return (-1);
	}
	return (0);
}

static int	ft_var_init(char **buffer, char **remainder, int *read_bytes, int fd)
{
	*buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buffer)
		return (-1);
	*buffer[0] = '\0';
	if (!*remainder)
	{
		*remainder = ft_strdup("\0");
		if (!*remainder)
			return (-1);
	}
	*read_bytes = read(fd, *buffer, BUFFER_SIZE);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*temp;
	char		*buffer;
	int			read_bytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (ft_var_init(&buffer, &remainder, &read_bytes, fd) == -1)
		return (-1);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
		if (ft_strchr(remainder, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_return(line, &remainder, read_bytes));
}
