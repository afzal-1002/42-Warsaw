/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 03:30:01 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/03 00:30:14 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_check_char(char *str, int *c)
{
	while (str[*c] == ' ' || str[*c] == '\t' || str[*c] == '\n'
		|| str[*c] == '\v' || str[*c] == '\f' || str[*c] == '\r')
	{
		(*c)++;
	}
}

int	ft_atoi(char *str)
{
	int	c;
	int	sign;
	int	result;

	c = 0;
	sign = 1;
	result = 0;
	ft_check_char(str, &c);
	while (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
		{
			sign = -sign;
		}
		c++;
	}
	while ((str[c] >= '0' && str[c] <= '9'))
	{
		result = result * 10 + (str[c] - '0');
		c++;
	}
	return (result * sign);
}

/*
int	main(void)
{
	char	str[] = " \t\t\t   ++--123--4+++bullshit---5dfasf45454";
	int		num;

	num = ft_atoi(str);
	printf("%d \n", num);
	return (0);
}
*/
