/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:40:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/23 13:14:33 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    {
        ScavTrap scav("C3CS4");

        std::cout << scav.getName() << " has " << scav.getHitPoints()
            << " hit points, " << scav.getEnergyPoints()
            << " energy points and " << scav.getAttackDamage()
            << " attack damage." << std::endl;

        scav.attack("broken drone");
        scav.guardGate();
        scav.takeDamage(25);
        scav.beRepaired(15);

        ScavTrap copyScav(scav);
        copyScav.guardGate();
        copyScav = scav;

                std::cout << copyScav.getName() << " has " << copyScav.getHitPoints()
            << " hit points, " << copyScav.getEnergyPoints()
            << " energy points and " << copyScav.getAttackDamage()
            << " attack damage." << std::endl;
    }

    return 0;
}
