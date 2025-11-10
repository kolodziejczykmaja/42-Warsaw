/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:23:29 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/03/07 19:54:10 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printing(va_list *args, const char symbol, size_t *counter)
{
	if (symbol == 'c')
		ft_putchar (va_arg (*args, int), counter);
	if (symbol == 's')
		ft_putstr (va_arg (*args, char *), counter);
	if (symbol == 'p')
		ft_putptr ((unsigned long long)(va_arg (*args, void *)), counter);
	if (symbol == 'd' || symbol == 'i')
		ft_putnbr (va_arg (*args, int), counter);
	if (symbol == 'u')
		ft_putunbr (va_arg (*args, unsigned int), counter);
	if (symbol == 'x' || symbol == 'X')
		ft_putnbr_base (va_arg (*args, unsigned int), counter, symbol);
	if (symbol == '%')
		ft_putchar ('%', counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	size_t	counter;

	counter = 0;
	i = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printing (&args, format[i], &counter);
		}
		else
		{
			ft_putchar (format[i], &counter);
		}
		i++;
	}
	va_end(args);
	return (counter);
}
// #include <stdio.h>
// int main ()
// {
// 	int i = ft_printf (" %p %p ", 0, 0);
// 	printf ("\n%d\n", i);
// 	int j = printf (" %p %p ", 0, 0);
// 	printf ("\n%d\n", j);
// 	return (0);
// }