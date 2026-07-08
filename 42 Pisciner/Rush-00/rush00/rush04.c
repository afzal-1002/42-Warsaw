/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:59:29 by mafzal            #+#    #+#             */
/*   Updated: 2024/08/25 21:07:01 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_edges(int col, int row, int width, int height)
{
	if (row == 0 || row == height - 1)
	{
		ft_putchar('B');
	}
	else if (col == 0 || col == width - 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	print_corners(int col, int row, int width, int height)
{
	if ((col == 0 && row == 0))
	{
		ft_putchar('A');
	}
	else if ((col == 0 && row == height - 1))
	{
		ft_putchar('C');
	}
	else if ((col == width - 1 && row == 0))
	{
		ft_putchar('C');
	}
	else if ((col == width - 1 && row == height - 1))
	{
		ft_putchar('A');
	}
	else
	{
		print_edges(col, row, width, height);
	}
}

void	rush(int width, int height)
{
	int	row;
	int	col;

	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			print_corners(col, row, width, height);
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}
