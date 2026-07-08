/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:11:12 by mafzal            #+#    #+#             */
/*   Updated: 2024/08/25 21:46:38 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_check_isvalid(char *argv, int *i)
{
	while (argv[*i] == ' ')
	{
		(*i)++;
	}
	if (argv[*i] == '-' || argv[*i] == '\\' || argv[*i] == '('
		|| argv[*i] == '@' || argv[*i] == '!' || argv[*i] == '*')
	{
		return (0);
	}
	if (argv[*i] == '+')
	{
		(*i)++;
	}
	return (1);
}

int	convert_number(char *argv)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (!ft_check_isvalid(argv, &i))
	{
		return (0);
	}
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		result = result * 10 + (argv[i] - '0');
		i++;
	}
	if (argv[i] != '\0')
	{
		return (0);
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	width;
	int	height;

	if (argc == 3)
	{
		width = convert_number(argv[1]);
		height = convert_number(argv[2]);
		if (height < 0 || width < 0 || height == 0 || width == 0)
		{
			write(1, "Invalid - input positive number(X): X X", 39);
			return (0);
		}
		else
		{
			rush(width, height);
		}
	}
	else
	{
		write(1, "Invalid - input positive number(X): X X", 39);
	}
	return (0);
}
