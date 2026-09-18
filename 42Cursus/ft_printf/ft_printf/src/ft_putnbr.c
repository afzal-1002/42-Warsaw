/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:51:35 by mafzal            #+#    #+#             */
/*   Updated: 2025/03/03 13:44:17 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putnbr(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		if (n / 10 != 0)
			i += ft_putnbr(-(n / 10));
		i += ft_putchar('0' - (n % 10));
		return (i);
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
