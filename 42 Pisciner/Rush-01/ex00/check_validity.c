/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:13:14 by jzackiew          #+#    #+#             */
/*   Updated: 2024/09/01 20:29:05 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources.h"

bool	check_duplicates(int *line, int n)
{
	int	i;
	int	j;

	i = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n - 1)
		{
			if (line[j] == line[i])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_visibility(int *line, int requirement, int n)
{
	int	i;
	int	counter;
	int	biggest_num;

	i = 0;
	counter = 1;
	biggest_num = line[0];
	while (i < n)
	{
		if (line[i] > biggest_num)
		{
			biggest_num = line[i];
			counter++;
		}
		i++;
	}
	if (counter == requirement)
		return (true);
	else
		return (false);
}

bool	check_ver_req_line(int x, int y, int id_of_side, t_grid_data *data)
{
	int	*line;
	int	counter;

	counter = 0;
	line = malloc(data->n * 4);
	while (y < data->n)
	{
		line[y] = data->grid[y][x];
		y++;
	}
	if (check_duplicates(line, data->n) && check_visibility(line,
			data->requirements[id_of_side][x], data->n))
		return (true);
	else
		return (false);
}

int	check_side(t_grid_data *data, int id_of_line, int id_of_side)
{
	if (id_of_side == 0)
		return (check_upper_side(data, id_of_line, id_of_side));
	if (id_of_side == 1)
		return (check_lower_side(data, id_of_line, id_of_side));
	if (id_of_side == 2)
		return (check_left_side(data, id_of_line, id_of_side));
	if (id_of_side == 3)
		return (check_right_side(data, id_of_line, id_of_side));
	return (0);
}

int	is_grid_valid(t_grid_data *data)
{
	int	id_of_side;
	int	id_of_line;
	int	output;

	id_of_side = 0;
	output = 0;
	while (id_of_side < 4)
	{
		id_of_line = 0;
		while (id_of_line < data->n)
		{
			if (!check_side(data, id_of_line, id_of_side))
				return (0);
			id_of_line++;
		}
		id_of_side++;
	}
	return (1);
}
