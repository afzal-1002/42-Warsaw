/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halam <halam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:27:55 by halam             #+#    #+#             */
/*   Updated: 2024/08/25 20:52:35 by halam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_character(int x, int y, int col, int row)
{
	if (x != 0 && x < col -1 && y != 0 && y < row -1)
	{
		ft_putchar (' ');
	}
	else if ((x > 0 && x < col -1) && (y == 0 || y == row -1))
	{
		ft_putchar ('-');
	}
	else if ((x == 0 || x == col -1) && (y > 0 && y < row -1))
	{
		ft_putchar ('|');
	}
	else
	{
		ft_putchar ('o');
	}
}

void	rush(int col, int row)
{
	int		x;
	int		y;

	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			print_character (x, y, col, row);
			x++;
		}
		write (1, "\n", 1);
		y++;
	}
}
