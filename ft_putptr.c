/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:28:25 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/03/07 19:54:18 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rec(unsigned long long n, size_t *counter)
{
	unsigned long long	len;
	char				*base;

	len = 16;
	base = "0123456789abcdef";
	if (n >= len)
	{
		rec(n / len, counter);
		n %= len;
	}
	ft_putchar((char)base[n], counter);
}

void	ft_putptr(unsigned long int n, size_t *counter)
{
	ft_putstr("0x", counter);
	rec(n, counter);
}
