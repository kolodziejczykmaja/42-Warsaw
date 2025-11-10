/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:23:31 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/01/18 20:45:48 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	convert_c;
	unsigned char	*convert_s;

	i = 0;
	convert_c = (unsigned char)c;
	convert_s = (unsigned char *)s;
	while (i < n)
	{
		convert_s[i] = convert_c;
		i++;
	}
	return (s);
}
