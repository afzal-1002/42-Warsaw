/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:25:31 by agarbacz          #+#    #+#             */
/*   Updated: 2024/09/01 22:27:12 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources.h"

bool	check_line_dups(t_grid_data *data, int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < data->n)
	{
		if (data->grid[row][x] == num || data->grid[x][col] == num)
		{
			return (false);
		}
		x++;
	}
	return (true);
}

void	handle_grid(t_grid_data *data, int row, int col)
{
	int	num;

	num = 1;
	while (num <= data->n)
	{
		if (check_line_dups(data, row, col, num))
		{
			data->grid[row][col] = num;
			generate_permutations(data, row, col + 1);
			data->grid[row][col] = 0;
		}
		num++;
	}
}

void	generate_permutations(t_grid_data *data, int row, int col)
{
	if (row == data->n)
	{
		if (is_grid_valid(data))
		{
			print_grid(data);
			data->found_valid_grid = 1;
		}
		return ;
	}
	if (col == data->n)
	{
		generate_permutations(data, row + 1, 0);
		return ;
	}
	handle_grid(data, row, col);
}

int	solve_grid(t_grid_data *data)
{
	int	result;

	result = 1;
	data->found_valid_grid = 0;
	generate_permutations(data, 0, 0);
	if (!(data->found_valid_grid == 1))
	{
		result = 0;
	}
	return (result);
}
