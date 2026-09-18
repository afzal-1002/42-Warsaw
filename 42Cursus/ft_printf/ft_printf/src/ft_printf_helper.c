/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:57:17 by mafzal            #+#    #+#             */
/*   Updated: 2025/02/18 21:39:40 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_puthex(unsigned long int n, char c)
{
	int		count;
	char	*digit;

	count = 0;
	if (c == 'X')
		digit = "0123456789ABCDEF";
	else
		digit = "0123456789abcdef";
	if (n == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (n >= 16)
		count += ft_puthex(n / 16, c);
	count += write(1, &digit[n % 16], 1);
	return (count);
}
