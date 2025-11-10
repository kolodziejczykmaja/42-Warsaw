/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkolodzi <mkolodzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:29:26 by mkolodzi          #+#    #+#             */
/*   Updated: 2025/03/07 19:50:15 by mkolodzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, size_t *counter);
void	ft_putstr(char *str, size_t *counter);
void	ft_putnbr(int n, size_t *counter);
void	ft_putunbr(unsigned int n, size_t *counter);
void	ft_putnbr_base(unsigned int n, size_t *counter, const char symbol);
void	ft_putptr(unsigned long int n, size_t *counter);

#endif