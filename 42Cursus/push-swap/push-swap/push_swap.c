/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:50:37 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 18:03:29 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	swap;
	int			size;

	swap.a = NULL;
	swap.b = NULL;
	swap.numbers = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		swap.split = ft_split(argv[1]);
	else
		swap.split = argv + 1;
	size = list_size(swap.split);
	swap.numbers = prepare_stack(swap.split, &swap.a, size);
	if (!swap.numbers || has_duplicate(swap.numbers, size))
	{
		mem_clear(&swap, argc);
		return (1);
	}
	assign_index(swap.a, swap.numbers, size);
	radix_sort(&swap.a, &swap.b, size);
	mem_clear(&swap, argc);
	return (0);
}
