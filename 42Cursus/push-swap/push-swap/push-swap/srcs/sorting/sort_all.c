/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:51:09 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 16:28:24 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_all(t_list **a, t_list **b, int size, int max_bits)
{
	int	i;
	int	j;
	int	pushed;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		pushed = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
			{
				pb(a, b);
				pushed++;
			}
			j++;
		}
		while (pushed--)
			pa(a, b);
		i++;
	}
}
