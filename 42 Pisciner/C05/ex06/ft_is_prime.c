/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:51:42 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/04 22:31:08 by mafzal           ###   ########.fr       */
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

/*
int	main(void)
{
	int	nb;
	int	ans;

	nb = 30;
	ans = ft_is_prime(nb);
	printf("is as Prime number %d", ans);
	return (0);
}
*/