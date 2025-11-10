#include "get_next_line.h"

ssize_t ft_strlen(const char *s)
{
	ssize_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len + 1;
	result = malloc(sizeof(char) * len);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		result[i + s1_len] = s2[i];
		i++;
	}
	result[i + s1_len] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (result);
}