/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:28:32 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/03/07 18:30:40 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, size_t *counter)
{
	if (n >= 10)
	{
		ft_putunbr (n / 10, counter);
		n = n % 10;
	}
	ft_putchar (n + '0', counter);
}
