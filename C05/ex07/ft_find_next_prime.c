/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:26:40 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/04 22:31:05 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	num;
	int	mod;

	num = 2;
	if (nb <= 1)
		return (0);
	while (num * num <= nb)
	{
		mod = nb % num;
		if (mod == 0)
			return (0);
		num++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	result;

	result = 0;
	while (result == 0)
	{
		result = ft_is_prime(nb);
		if (result == 1)
		{
			return (nb);
		}
		else
		{
			nb = nb + 1;
			ft_is_prime(nb);
		}
	}
	return (nb);
}

/*
int	main(void)
{
	int	nb;
	int	ans;

	nb = 25;
	ans = ft_find_next_prime(nb);
	printf("%d", ans);
	return (0);
}
*/