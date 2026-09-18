/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:19:43 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 18:19:45 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	result;

	if (!str || !str[0])
		print_error();
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		print_error();
	result = parse_number(str, sign, i);
	return ((int)(result * sign));
}

long	parse_number(const char *str, int sign, int i)
{
	long	result;

	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error();
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			print_error();
		i++;
	}
	return (result);
}
