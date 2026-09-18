#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Define the linked list structure for stack elements */
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*All Algorithm*/
/* swap */
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);

/* push */
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);

/* rotate */
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);

/* reverse rotate */
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

/* linked list functions */
t_list				*create_node(int value);
t_list				*append_node(t_list **head, int value);
t_list				*get_last_node(t_list *head);
t_list				*get_node_by_index(t_list *head, int index);
t_list				*find_node_by_value(t_list *head, int value);
void				reset_index(t_list *stack);
void				free_node(t_list *node);
void				free_stack(t_list *head);

/* utility functions */
int					is_space(char c);
int					is_char(char c);
int					ft_atoi(const char *str);
int					get_max_bits(int max_index);
/* string split */
char				**ft_split(char const *s);
int					word_count(char *str);
char				*word_dup(char *str, int start, int finish);
void				free_split(char **split);

/* sorting algorithms */
void				sort_three(t_list **stack);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				radix_sort(t_list **stack_a, t_list **stack_b, int size,
						int max_bits);

/* array utilities */
void				swap(int *a, int *b);
void				quick_sort(int arr[], int start, int end);
void				bubble_sort(int *arr, int size);
int					is_sorted(int *arr, int size);

/* index assignment */
void				print_error(void);
void				assign_index(t_list *stack, int *sorted, int size);

#endif
