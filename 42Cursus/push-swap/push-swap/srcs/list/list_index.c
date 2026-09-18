/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:52:13 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/25 20:54:28 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reset_index(t_list *stack)
{
	while (stack)
	{
		stack->index = -1;
		stack = stack->next;
	}
}

void	assign_index(t_list *a, int *sorted, int size)
{
	int		i;
	t_list	*cur;

	cur = a;
	while (cur)
	{
		i = 0;
		while (i < size && sorted[i] != cur->value)
			i++;
		if (i == size)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		cur->index = i;
		cur = cur->next;
	}
}
