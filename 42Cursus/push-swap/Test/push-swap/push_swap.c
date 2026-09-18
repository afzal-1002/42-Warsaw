/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:50:37 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 15:47:14 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal <mafzal@student.42warsaw.pl>         +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:50:37 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 16:00:00 by mafzal           ###   ########.fr       */
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
	swap.split = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		swap.split = ft_split(argv[1]);
	else
		swap.split = argv + 1;
	size = list_size(swap.split);
	if (!init_numbers(&swap, size, argc))
		return (1);
	assign_index(swap.a, swap.numbers, size);
	radix_sort(&swap.a, &swap.b, size);
	mem_clear(&swap, argc);
	return (0);
}
