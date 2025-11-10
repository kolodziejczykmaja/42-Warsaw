#include <unistd.h>

int	leng(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_key(char *str)
{
	int	i;

	i = 0;
	if (leng(str) > 39)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
