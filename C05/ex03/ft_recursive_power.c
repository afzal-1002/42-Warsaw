/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:49:47 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/04 22:31:16 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	int	ans;

	ans = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	ans = nb * ft_recursive_power(nb, power - 1);
	return (ans);
}

/*
int	main(void)
{
	int	num;

	num = 0;
	num = ft_recursive_power(3, 2);
	printf("%d", num);
	return (0);
}
*/