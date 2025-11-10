/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:45:23 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/01/19 22:23:00 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counting(int n)
{
	int	amount;

	amount = 0;
	if (n <= 0)
		amount++;
	while (n)
	{
		n /= 10;
		amount++;
	}
	return (amount);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		amount;
	long	number;

	number = n;
	amount = counting(n);
	result = malloc((amount + 1) * sizeof(char));
	if (n < 0)
	{
		result[0] = '-';
		number *= -1;
	}
	if (!result)
		return (NULL);
	result[amount--] = '\0';
	if (n == 0)
		result[0] = '0';
	while (number)
	{
		result[amount--] = (number % 10) + '0';
		number /= 10;
	}
	return (result);
}
