/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:51:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 15:39:43 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal <mafzal@student.42warsaw.pl>         +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:51:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 16:00:00 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	*prepare_stack(char **split, t_list **a, int size)
{
	int	i;
	int	*numbers;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!is_valid_number(split[i]))
		{
			free(numbers);
			return (NULL);
		}
		i++;
	}
	list_fill(split, a, numbers, size);
	quick_sort(numbers, 0, size - 1);
	return (numbers);
}
