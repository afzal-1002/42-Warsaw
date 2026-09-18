/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:51:05 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/25 20:51:06 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	radix_sort(t_list **a, t_list **b, int size)
{
	int	max_bits;

	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
	{
		max_bits = get_max_bits(size - 1);
		sort_all(a, b, size, max_bits);
	}
}
