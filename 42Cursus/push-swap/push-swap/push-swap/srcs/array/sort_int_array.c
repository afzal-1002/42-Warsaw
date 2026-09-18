/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:52:56 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/25 21:00:02 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	quick_sort(int arr[], int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	if (start >= end)
		return ;
	pivot = arr[end];
	i = start;
	j = start;
	while (i < end)
	{
		if (arr[i] < pivot)
		{
			ft_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	ft_swap(&arr[j], &arr[end]);
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
