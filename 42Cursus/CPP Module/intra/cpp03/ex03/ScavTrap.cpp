/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:40:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/22 10:28:02 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->name << " copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap " << name << " assignment operator called." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ScavTrap " << name << " can't attack because it has no hit points left." << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " can't attack because it has no energy points left." << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
