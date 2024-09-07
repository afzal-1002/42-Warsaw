/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:09:16 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/05 01:29:53 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= nb)
	{
		nb = nb - i;
		i += 2;
	}
	if (nb == 0)
	{
		return ((i - 1) / 2);
	}
	return (0);
}

/*
int	ft_sqrt2(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
		{
			return (i);
		}
		else
			i++;
	}
	return (0);
}
*/

/*
int	main(void)
{
	int	num;
	int	ans;
	int	ans2;

	num = 25;
	ans = ft_sqrt2(num);
	ans2 = ft_sqrt(num);
	printf("%d\n", ans);
	printf("with subtract %d", ans2);
	return (0);
}
*/