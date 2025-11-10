/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:59:10 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/01/19 20:14:18 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	counter;

	counter = 0;
	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
	{
		dst_len++;
	}
	src_len = ft_strlen(src);
	if (dst_len == size)
	{
		return (size + src_len);
	}
	while (dst_len + counter + 1 < size && src[counter] != '\0')
	{
		dst[dst_len + counter] = src[counter];
		counter++;
	}
	dst[dst_len + counter] = '\0';
	return (dst_len + src_len);
}
