#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
static int	ft_get_int_length(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static void	ft_fill_string(char *result, int n, int length)
{
	int	current;

	if (n < 0)
	{
		length++;
		result[0] = '-';
	}
	current = 0;
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		if (n < 0)
			current = (-1) * (n % 10);
		else
			current = n % 10;
		n = n / 10;
		length--;
		result[length] = current + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	length = ft_get_int_length(n);
	if (n < 0)
		result = malloc(sizeof(char) * (length + 2));
	else
		result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (0);
	ft_fill_string(result, n, length);
	if (n < 0)
		result[length + 1] = 0;
	else
		result[length] = 0;
	return (result);
}

int main(void)
{
//	write(1, "in main\n", 8);
	printf("%lu\n", BUFFER_SIZE);
	int fd = 0; //open("testtxt", O_RDONLY);
	char *line;
	int done = 0;
	if (fd > -1)
	{
		write(1, "in fd\n", 6);
		while(line)
		{
//			write(1, "befor gnl\n", 10);
			line = get_next_line(fd);
//			write(1, "after gnl\n", 10);
			if (line)
			{
				printf("%s", line);
				free(line);
			}
		}
	} else
	{
		printf("opening error");
	}
	return (0);
}
