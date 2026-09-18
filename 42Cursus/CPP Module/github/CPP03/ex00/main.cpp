/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:59:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/23 12:02:40 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("C3CS4");

    clap.setAttackDamage(3);
    std::cout << clap.getName() << " has " << clap.getHitPoints()
              << " hit points, " << clap.getEnergyPoints()
              << " energy points and " << clap.getAttackDamage()
              << " attack damage." << std::endl;

    clap.attack("training dummy");
    clap.takeDamage(4);
    clap.beRepaired(2);

        std::cout << clap.getName() << " has " << clap.getHitPoints()
              << " hit points, " << clap.getEnergyPoints()
              << " energy points and " << clap.getAttackDamage()
              << " attack damage." << std::endl;

    return 0;
}
