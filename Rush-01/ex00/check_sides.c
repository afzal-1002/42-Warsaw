/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:12:04 by jzackiew          #+#    #+#             */
/*   Updated: 2024/09/01 20:32:59 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources.h"

int	check_upper_side(t_grid_data *data, int id_of_line, int id_of_side)
{
	int	*line;
	int	counter;

	line = malloc(data->n * 4);
	counter = 0;
	while (counter < data->n)
	{
		line[counter] = data->grid[counter][id_of_line];
		counter++;
	}
	if (check_duplicates(line, data->n) && check_visibility(line,
			data->requirements[id_of_side][id_of_line], data->n))
		return (1);
	else
		return (0);
}

int	check_lower_side(t_grid_data *data, int id_of_line, int id_of_side)
{
	int	*line;
	int	counter;

	line = malloc(data->n * 4);
	counter = data->n - 1;
	while (counter >= 0)
	{
		line[data->n - counter - 1] = data->grid[counter][id_of_line];
		counter--;
	}
	if (check_duplicates(line, data->n) && check_visibility(line,
			data->requirements[id_of_side][id_of_line], data->n))
		return (1);
	else
		return (0);
}

int	check_left_side(t_grid_data *data, int id_of_line, int id_of_side)
{
	int	*line;
	int	counter;

	line = malloc(data->n * 4);
	counter = 0;
	while (counter < data->n)
	{
		line[counter] = data->grid[id_of_line][counter];
		counter++;
	}
	if (check_duplicates(line, data->n) && check_visibility(line,
			data->requirements[id_of_side][id_of_line], data->n))
		return (1);
	else
		return (0);
}

int	check_right_side(t_grid_data *data, int id_of_line, int id_of_side)
{
	int	*line;
	int	counter;

	line = malloc(sizeof(int));
	counter = data->n - 1;
	while (counter >= 0)
	{
		line[data->n - counter - 1] = data->grid[id_of_line][counter];
		counter--;
	}
	if (check_duplicates(line, data->n) && check_visibility(line,
			data->requirements[id_of_side][id_of_line], data->n))
		return (1);
	else
		return (0);
}
