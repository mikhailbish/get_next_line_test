#include "gnl.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	char	*result;
	int		counter;

	counter = 0;
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(total_length * sizeof(char));
	if (!result)
		return (0);
	while (s1 && *s1)
	{
		result[counter] = *s1;
		counter++;
		s1++;
	}
	while (s2 && *s2)
	{
		result[counter] = *s2;
		counter++;
		s2++;
	}
	result[counter] = 0;
	return (result);
}

static int	get_line_length(const char *s)
{
	int	counter;

	counter = 0;
	while (s && s[counter] && s[counter] !='\n')
		counter++;
	if (s && s[counter] == '\n')
		counter++;
	return (counter);
}
static void	ft_populate(char const *s, size_t len, int counter, char *result)
{
	while (s[counter] && (len - counter))
	{
		result[counter] = s[counter];
		counter++;
	}
	result[len] = 0;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		counter;

	counter = 0;
	result = 0;
	if (start > ft_strlen(s))
	{
		result = (char *)malloc(sizeof(char));
		if (!result)
			return (0);
		*result = 0;
		return (result);
	}
	s += start;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_populate(s, len, counter, result);
	return (result);
}

int	parse_buffer(t_list **head, char *buffer)
{
	t_list	*tmp;
	int		line_length;
	char	*content;
	size_t	buffer_index;

	buffer_index = 0;
	content = 0;
	tmp = 0;
	while (get_line_length(buffer + buffer_index))
	{
		content = ft_substr(buffer, buffer_index, get_line_length(buffer + buffer_index));
		if (!content)
			return (0);
		tmp = ft_lstnew(content);
		if (!tmp)
			return (0);
		ft_lstadd_back(head, tmp);
		buffer_index += get_line_length(buffer + buffer_index);
	}
	return (1);
}

static char	*give_line(t_list *head)
{
	size_t length;
	char *line;
	char *tmp;

	tmp = 0;
	length = ft_strlen(head->content);
	while (length)
	{
		printf("%s\n", head->content);
		tmp = ft_strjoin(line, (char *)head->content);
		if (!tmp)
			return (0);
		line = tmp;
		if (line[ft_strlen(line) - 1] != '\n')
		{
			head = head->next;
			length = ft_strlen(head->content);
		}
		else
		{
			return (line);
		}
	}
	return (0);
}

/* build lines */
t_list *clearnl(t_list *nl)
{
	t_list *tmp;
	size_t length;
	char *cont;

	tmp = 0;
	if (nl)
	{
		while (nl->next)
		{
			length = ft_strlen((char *)nl->content);
			tmp = nl;
			cont = nl->content;
			if (length)
			{
				if (cont[length - 1] == '\n')
				{
					nl = nl->next;
					break;
				}
			}
			nl = nl->next;
			free(tmp);
		}
	}
	return (nl);
}

char	*get_next_line(int fd)
{
	static t_list	**nl_list = 0;
	char			*r_buffer;
	char *nl = 0;
	if (!nl_list)
	{
		nl_list  = malloc(sizeof(t_list *));
		*nl_list = 0;
	} else {
	}

	r_buffer = malloc(BUFFER_SIZE);
	if (!r_buffer)
	{
		return (0);
	}
	if (read(fd, r_buffer, BUFFER_SIZE))
	{
		parse_buffer(nl_list, r_buffer);
		free(r_buffer);
	}
	if (*nl_list)
	{
		nl = give_line(*nl_list);
		*nl_list = clearnl(*nl_list);
	}
	return (nl);
}
