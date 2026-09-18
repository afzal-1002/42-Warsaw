/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:51:39 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/25 20:51:40 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*node;

	if (!b || !*b)
		return ;
	node = *b;
	*b = node->next;
	node->next = *a;
	*a = node;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node;

	if (!a || !*a)
		return ;
	node = *a;
	*a = node->next;
	node->next = *b;
	*b = node;
	write(1, "pb\n", 3);
}
