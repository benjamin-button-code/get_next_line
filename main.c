#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		printf("----------------------------------------\n");
	}
	free(line);
	return (0);
}
