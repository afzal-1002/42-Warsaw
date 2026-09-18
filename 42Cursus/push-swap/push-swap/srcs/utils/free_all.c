/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:49:26 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 15:13:54 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	mem_clear(t_push_swap *swap, int argc)
{
	if (swap->numbers)
	{
		free(swap->numbers);
		swap->numbers = NULL;
	}
	if (swap->a)
		free_stack(&swap->a);
	if (swap->b)
		free_stack(&swap->b);
	if (argc == 2 && swap->split)
		free_split(swap->split);
}
