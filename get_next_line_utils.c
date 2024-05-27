#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	while (*s1)
	{
		result[counter] = *s1;
		counter++;
		s1++;
	}
	while (*s2)
	{
		result[counter] = *s2;
		counter++;
		s2++;
	}
	result[counter] = 0;
	return (result);
}

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*ptr;

	length = ft_strlen(s1);
	ptr = malloc((length + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (*s1)
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	*ptr = 0;
	return (ptr - length);
}
