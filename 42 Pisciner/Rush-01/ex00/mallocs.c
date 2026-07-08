/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:36:03 by agarbacz          #+#    #+#             */
/*   Updated: 2024/09/01 22:42:36 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources.h"

int	count_nums(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if ((str[i] != ' ') && (str[i] >= '0' && str[i] <= '9'))
		{
			res++;
		}
		i++;
	}
	return (res);
}

int	get_inp_size(int res)
{
	if (res == 16)
		return (4);
	if (res == 25)
		return (5);
	if (res == 36)
		return (6);
	if (res == 49)
		return (7);
	if (res == 64)
		return (8);
	if (res == 81)
		return (9);
	return (-1);
}

int	**alloc_grid(int arr_size)
{
	int	**arr;
	int	i;

	arr = malloc(arr_size * sizeof(int *));
	i = 0;
	while (i < arr_size)
	{
		arr[i] = malloc(arr_size * sizeof(int));
		i++;
	}
	return (arr);
}

int	**alloc_req(int arr_size)
{
	int	**arr;
	int	i;

	arr = malloc(4 * sizeof(int *));
	i = 0;
	while (i < arr_size)
	{
		arr[i] = malloc(arr_size * sizeof(int));
		i++;
	}
	return (arr);
}

void	export_req(char *input, t_grid_data *data)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < data->n)
	{
		j = 0;
		while (j < data->n)
		{
			if (input[k] <= '9' && input[k] >= '0')
			{
				data->requirements[i][j] = input[k] - '0';
				j++;
			}
			k++;
		}
		i++;
	}
}
