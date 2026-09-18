
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*t;
	char	*str;
	char	**split;
	int		i;
	int		total_number;
	int		*numbers;
	int		num;
	int		count;
	t_list	*a;
	t_list	*b;
	int		max_bits;
	int		max_index;

	a = NULL;
	b = NULL;
	// b = create_node(5);
	// if (b)
	// 	printf("B Stack Value: %d, Index: %d\n", b->value, b->index);
	total_number = 0;
	if (argc == 2)
	{
		str = argv[1];
		split = ft_split(str);
	}
	else
	{
		split = (char **)malloc((argc) * sizeof(char *));
		i = 0;
		while (argc >= 2)
		{
			split[i] = argv[i + 1];
			i++;
			argc--;
		}
		split[i] = '\0';
	}
	total_number = 0;
	while (split[total_number])
		total_number++;
	numbers = (int *)malloc((total_number) * sizeof(int));
	printf("Total Numbers from split in main: %d\n", total_number);
	i = 0;
	// while (split[i])
	// {
	// 	printf("%s ", split[i]);
	// 	i++;
	// }
	count = 0;
	i = 0;
	while (split[i])
	{
		num = ft_atoi(split[i]);
		numbers[count++] = num;
		append_node(&a, num);
		i++;
	}
	if (!(is_sorted(numbers, total_number)))
	{
		quick_sort(numbers, 0, total_number - 1);
		printf("The array is not sorted.\n");
	}
	else
	{
		printf("The array is sorted.\n");
	}
	max_index = total_number - 1;
	max_bits = get_max_bits(max_index);
	printf("max_index = %d max_bit = %d.\n", max_index, max_bits);
	t = a;
	while (t)
	{
		printf("BEFORE indexing → value=%d index=%d\n", t->value, t->index);
		t = t->next;
	}
	assign_index(a, numbers, total_number);
	printf("\n\n\n");
	for (i = 0; i < count; i++)
	{
		printf("Array Sorted → value=%d index=%d\n", numbers[i], i);
	}
	// t = a;
	// while (t)
	// {
	// 	printf("AFTER indexing → value=%d index=%d\n", t->value, t->index);
	// 	t = t->next;
	// }
	radix_sort(&a, &b, total_number, max_bits);
	t = a;
	while (t)
	{
		printf("AFTER Sorting Stack → value=%d index=%d\n", t->value, t->index);
		t = t->next;
	}
	return (0);
}
