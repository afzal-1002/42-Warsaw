#include "../../push_swap.h"

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_list	*append_node(t_list **head, int value)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = create_node(value);
	if (!new_node)
		return (NULL);
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	return (new_node);
}

void	reset_index(t_list *stack)
{
	while (stack)
	{
		stack->index = -1;
		stack = stack->next;
	}
}
t_list	*get_last_node(t_list *current)
{
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_list	*get_node_by_index(t_list *head, int index)
{
	while (head)
	{
		if (head->index == index)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_list	*find_node_by_value(t_list *head, int value)
{
	while (head)
	{
		if (head->value == value)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	free_stack(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_node(t_list *node)
{
	if (node)
		free(node);
}

int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	tmp->prev = NULL;
	*a = tmp;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	tmp->prev = NULL;
	*b = tmp;
}

void	ra(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	(*a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}
