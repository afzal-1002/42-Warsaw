/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:37:42 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/05 00:20:57 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	ans;

	ans = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 0)
	{
		ans *= nb;
		power--;
	}
	return (ans);
}
/*
int	main(void)
{
	int	num;

	num = 0;
	num = ft_iterative_power(0, 1);
	printf("%d", num);
	return (0);
}
*/