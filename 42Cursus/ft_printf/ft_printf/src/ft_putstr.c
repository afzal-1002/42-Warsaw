/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:17:22 by mafzal            #+#    #+#             */
/*   Updated: 2025/02/18 17:17:58 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = -1;
	while (str[++count])
		ft_putchar(str[count]);
	return (count);
}
