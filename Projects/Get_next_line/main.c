#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd;
	char *line;

	// fd = open(argv[1], O_RDONLY);
	fd = 100000000;
	(void)argv;
	(void)argc;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	printf("%d\n", get_next_line(fd, &line));
	return 0;
}