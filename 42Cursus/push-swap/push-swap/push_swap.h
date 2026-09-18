/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:56:40 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 18:03:47 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Define the linked list structure for stack elements */
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_push_swap
{
	t_list			*a;
	t_list			*b;
	char			**split;
	int				*numbers;
}					t_push_swap;

/* array utilities */
void				ft_swap(int *a, int *b);
int					is_sorted(int *arr, int size);
void				bubble_sort(int *arr, int size);
void				quick_sort(int arr[], int size, int end);

/* libft_util */
int					ft_atoi(const char *str);
int					ft_is_char(char c);
int					ft_is_space(char c);
char				**ft_split(char const *s);
int					word_count(char *str);
char				*word_dup(char *str, int start, int finish);
char				**fill_words(char *str, char **result);
long				parse_number(const char *str, int sign, int i);
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

/* sorting algorithms */
int					*prepare_stack(char **split, t_list **a, int size);
void				sort_three(t_list **stack);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				sort_all(t_list **a, t_list **b, int size, int max_bits);
void				radix_sort(t_list **a, t_list **b, int size);
int					get_min_pos(t_list *stack);
int					is_sorted_stack(t_list *a);

/* linked list functions */
t_list				*create_node(int value);
t_list				*append_node(t_list **head, int value);
t_list				*get_last_node(t_list *head);
t_list				*get_node_by_index(t_list *head, int index);
t_list				*find_node_by_value(t_list *head, int value);
int					list_size(char **split);
void				list_fill(char **split, t_list **a, int numbers[],
						int size);
void				reset_index(t_list *stack);
int					has_duplicate(int *arr, int size);

/* Memory Free */
void				free_node(t_list *node);
void				free_split(char **split);
void				free_stack(t_list **stack);
void				mem_clear(t_push_swap *swap, int argc);

/* utility functions */
int					get_max_bits(int max_index);
int					stack_size(t_list *stack);

/* index assignment */
void				print_error(void);
void				assign_index(t_list *stack, int *sorted, int size);

#endif
