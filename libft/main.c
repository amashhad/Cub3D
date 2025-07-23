#include "get_next_line.h"
int	main()
{
	int fd = open("big.txt", O_RDONLY);
	int	line_cnt = 0;
	int	read_cnt = 0;
	char	*line = get_next_line(fd);
	while (line)
	{
		line_cnt += ft_strlen(line);
		read_cnt++;
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("line_cnt: %d\nread_cnt: %d\n", line_cnt, read_cnt);
	free(line);
	close(fd);
	return (0);
}
