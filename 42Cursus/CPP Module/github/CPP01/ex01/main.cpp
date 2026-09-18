/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:08:35 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/18 17:10:25 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		i;
	int		total;

	total = 5;
	horde = zombieHorde(total, "Foo");
	if (horde == NULL)
		return (1);
	i = 0;
	while (i < total)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}
