/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:28:19 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/03/07 19:50:18 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, size_t *counter)
{
	if (n == -2147483648)
	{
		ft_putstr ("-2147483648", counter);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar ('-', counter);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr (n / 10, counter);
			n = n % 10;
		}
		if (n < 10)
			ft_putchar (n + '0', counter);
	}
}
