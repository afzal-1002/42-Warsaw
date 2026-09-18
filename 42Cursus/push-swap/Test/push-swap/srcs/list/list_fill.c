/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:52:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/25 20:52:07 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	list_fill(char **split, t_list **stack_a, int numbers[], int size)
{
	int		i;
	int		num;
	t_list	*a;

	a = *stack_a;
	i = 0;
	while (i < size)
	{
		num = ft_atoi(split[i]);
		numbers[i] = num;
		append_node(&a, num);
		i++;
	}
	*stack_a = a;
}
