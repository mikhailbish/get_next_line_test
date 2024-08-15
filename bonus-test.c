#include "get_next_line_bonus.h"
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
	
//	printf("%lu\n", BUFFER_SIZE);
//	int fd = open("testtxt", O_RDONLY);
	char *line;
	char *some;
	int done = 0;
	int fds[1025];
	int i = 3;
	fds[0] = 0;
	fds[1] = 1;
	fds[2] = 2;
	
	while(i < 1025)
	{
		fds[i] = open("some", O_RDONLY);
		printf("opened %d\n", fds[i]);
		i++;
	}
	i = 0;
	while (i < 1025)
	{	
		if (i == 1)
		{
			i++;
			i++;
		}
		printf("%d fds[i]: %d\n", i, fds[i]);
		if (fds[i] > -1)
		{
			while(line)
			{
				line = get_next_line(fds[i]);
				if (line)
				{
					printf("%s", line);
					free(line);
				}
			}
			line = some;
			if (i != 0)
				close(fds[i]);
		} else
		{
			printf("opening error, i: %d fds[i]: %d\n", i, fds[i]);
		}
		i++;
	}
	return (0);
}
