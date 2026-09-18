/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:38:40 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/18 17:24:21 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	Level	level;
	int		i;

	std::string input;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	input = argv[1];
	i = 0;
	while (i < 4)
	{
		if (input == levels[i])
		{
			level = static_cast<Level>(i);
			harl.complain(level);
			return (0);
		}
		i++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
}
