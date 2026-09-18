/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:49 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/22 22:33:46 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_specifiers(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 117)
		count += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'X' || c == 'x')
		count += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (c == '%')
		count += ft_putchar('%');
	else
		count += write(1, "Unsupported format specifier \n", 30);
	return (count);
}
//#define va_arg(ap, type) (*(type *)((ap += sizeof(type)) - sizeof(type)))
