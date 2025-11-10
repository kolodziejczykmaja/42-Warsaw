/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:23:39 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/01/19 00:54:30 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			counter;
	unsigned char	*p1;
	unsigned char	*p2;

	if (n == 0)
		return (0);
	counter = 0;
	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	while (p1[counter] == p2[counter] && counter < n - 1)
	{
		counter++;
	}
	return ((int)(p1[counter] - p2[counter]));
}
