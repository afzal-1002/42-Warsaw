/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:51:17 by jzackiew          #+#    #+#             */
/*   Updated: 2024/09/01 21:53:08 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources.h"

void	print_grid(t_grid_data *data)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < data->n)
	{
		j = 0;
		while (j < data->n)
		{
			tmp = data->grid[i][j] + '0';
			write(1, &tmp, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_grid_data	*data;

	if (argc != 2 || count_nums(argv[1]) != 16)
	{
		write(1, "Error!", 7);
		write(1, "\n", 1);
		return (1);
	}
	data = (t_grid_data *)malloc(sizeof(t_grid_data));
	data->n = get_inp_size(count_nums(argv[1]));
	data->grid = alloc_grid(data->n);
	data->requirements = alloc_req(data->n);
	export_req(argv[1], data);
	if (solve_grid(data) == 0)
	{
		write(1, "No valid grid was found.\n", 25);
	}
	return (0);
}
