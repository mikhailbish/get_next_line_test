#include "gnl.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("testtxt", O_RDONLY);
	char *line;
	int done = 0;
	if (fd > 0)
	{
		while(line)
		{
			line = get_next_line(fd);
	//		if (line)
	//			printf("%s", line);
			if (!line)
				break;
//			free(line);
		}
	} else
	{
		printf("opening error");
	}
	return (0);
}
