/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:28:14 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/03/07 19:50:17 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_define_base(const char symbol)
{
	char	*base;

	if (symbol == 'x')
		base = "0123456789abcdef";
	if (symbol == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

void	ft_putnbr_base(unsigned int n, size_t *counter, const char symbol)
{
	char			*base;
	unsigned int	len;

	base = ft_define_base(symbol);
	len = 16;
	if (n >= len)
	{
		ft_putnbr_base(n / len, counter, symbol);
		n %= len;
	}
	ft_putchar((char)base[n], counter);
}
