/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:30:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/23 13:22:18 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    {
        FragTrap frag("C3CS4");
        
        std::cout << frag.getName() << " has " << frag.getHitPoints()
            << " hit points, " << frag.getEnergyPoints()
            << " energy points and " << frag.getAttackDamage()
            << " attack damage." << std::endl;

        frag.highFivesGuys();
        frag.attack("training dummy");
        frag.takeDamage(42);
        frag.beRepaired(10);

        FragTrap copy(frag);
        copy.highFivesGuys();
        copy = frag;
    }

    return 0;
}
