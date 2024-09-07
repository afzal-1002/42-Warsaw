/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:48:18 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/04 22:31:23 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	check;

	check = nb;
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	i = 1;
	while (check > 1)
	{
		nb = nb * i;
		i++;
		check--;
	}
	return (nb);
}

/*
int	main(void)
{
	int	num;
	int	ans;

	num = 5;
	ans = ft_iterative_factorial(num);
	printf("factorial %d", ans);
	return (0);
}
*/