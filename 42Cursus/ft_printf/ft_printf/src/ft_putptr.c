/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:39:45 by mafzal            #+#    #+#             */
/*   Updated: 2025/03/03 13:44:31 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putptr(void *ptr)
{
	int			i;
	uintptr_t	address;

	address = (uintptr_t)ptr;
	i = 0;
	if (!address)
		i += write(1, "(nil)", 5);
	else
	{
		i += ft_putstr("0x");
		i += ft_puthex(address, 'x');
	}
	return (i);
}
