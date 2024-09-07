/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:06:11 by mafzal            #+#    #+#             */
/*   Updated: 2024/08/21 20:18:23 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_displaychar(int n)
{
	int	firstnum;
	int	secondnum;

	if (n > 9)
	{
		firstnum = n / 10;
		secondnum = n % 10;
		ft_putchar (firstnum + '0');
		ft_putchar (secondnum + '0');
	}
	else
	{
		ft_putchar ('0');
		ft_putchar (n + '0');
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 99)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			ft_displaychar (num1);
			ft_putchar (' ');
			ft_displaychar (num2);
			if (num1 < 98 || num2 < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			num2++;
		}
		num1++;
	}
}
