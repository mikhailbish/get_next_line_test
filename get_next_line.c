# include "get_next_line.h"

int check_nl(char *s)
{
	char	*ptr;

	ptr = s;
	while(s && *s)
	{
		if (*s == '\n')
			return (s - ptr + 1);
		s++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*total_buffer = 0;
	char			buffer[BUFFER_SIZE + 1];
	int				read_bytes;
	char			*result;
	char			*tmp;
	int			end;

	tmp = 0;
	read_bytes = -1;
	while (!check_nl(total_buffer))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (0);
		if (read_bytes == 0)
			break;
		buffer[read_bytes] = 0;
		tmp = total_buffer;
		if (total_buffer == 0)
			total_buffer = "";
		total_buffer = ft_strjoin(total_buffer, buffer);
		free(tmp);
		tmp = 0;
	}
	if (check_nl(total_buffer))
	{
		end = ft_strlen(total_buffer);
		result = ft_substr(total_buffer, 0, check_nl(total_buffer));
		tmp = total_buffer;
		total_buffer = ft_substr(total_buffer, check_nl(total_buffer), end);
		free(tmp);
		tmp = 0;
		return (result);
	}
	else
	{
		if (total_buffer)
		{
			result = ft_strdup(total_buffer);
			free(total_buffer);
			total_buffer = 0;
		}
		else
			result = 0;
	}
	return (result);
}
