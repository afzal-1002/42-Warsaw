/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:51:10 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/01 02:05:39 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	num2;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	num2 = s1[i] - s2[i];
	return (num2);
}

/*
int	main(void)
{
	char	s1[] = "Hell";
	char	s2[] = "Hell";
	int		num;

	num = ft_strcmp(s1, s2);
	printf("%d", num);
}
*/