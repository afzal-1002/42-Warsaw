/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:51:16 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/25 20:51:17 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_five(t_list **a, t_list **b)
{
	int	pos;

	while (stack_size(*a) > 3)
	{
		pos = get_min_pos(*a);
		if (pos == 0)
			pb(a, b);
		else if (pos <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

int	get_min_pos(t_list *stack)
{
	int	min;
	int	pos;
	int	i;

	min = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}
