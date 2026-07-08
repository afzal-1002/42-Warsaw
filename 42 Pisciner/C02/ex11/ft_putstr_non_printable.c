/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:29:07 by mafzal            #+#    #+#             */
/*   Updated: 2024/08/29 00:43:46 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		num;
	char	*array;

	array = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		num = str[i];
		if (num < 0)
		{
			num += 256;
		}
		if (num < 32 || num > 126)
		{
			write(1, "\\", 1);
			write(1, &array[num / 16], 1);
			write(1, &array[num % 16], 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

/*
int	main(void)
{
	char	array[21] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(array);
	// printf("%s", array);
	return (0);
}
*/