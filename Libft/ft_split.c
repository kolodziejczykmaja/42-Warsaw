/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:35:44 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/01/19 22:16:36 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_sep(char str, char charset)
{
	if (str == charset)
		return (1);
	return (0);
}

static size_t	count_words(const char *str, char charset)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset)
			&& (i == 0 || is_sep(str[i - 1], charset)))
			counter++;
		i++;
	}
	return (counter);
}

static size_t	words_length(const char *str, size_t i, char charset)
{
	size_t	len;

	len = 0;
	while (str[i] && !is_sep(str[i], charset))
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(const char *str, char charset)
{
	char	**split;
	size_t	i;
	size_t	help;

	i = 0;
	help = 0;
	split = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!split)
		return (NULL);
	while (help < count_words(str, charset))
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			split[help] = ft_substr(str, i, words_length(str, i, charset));
			i += words_length(str, i, charset);
			help++;
		}
	}
	split[help] = NULL;
	return (split);
}
