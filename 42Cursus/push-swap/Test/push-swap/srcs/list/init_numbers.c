#include "../../push_swap.h"

int	init_numbers(t_push_swap *swap, int size, int argc)
{
	swap->numbers = prepare_stack(swap->split, &swap->a, size);
	if (!swap->numbers)
	{
		print_error();
		mem_clear(swap, argc);
		return (0);
	}
	if (has_duplicate(swap->numbers, size))
	{
		print_error();
		mem_clear(swap, argc);
		return (0);
	}
	mem_clear(swap, argc);
	return (1);
}
