#include "../../push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	assign_index(t_list *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == a->value)
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}


