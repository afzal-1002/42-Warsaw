/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:01:21 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/24 10:28:58 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << this->name << " copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assignment operator called." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructor called." << std::endl;
}

const std::string& ClapTrap::getName() const
{
    return name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return attackDamage;
}

void ClapTrap::setName(const std::string& value)
{
    name = value;
}

void ClapTrap::setHitPoints(unsigned int value)
{
    hitPoints = value;
}

void ClapTrap::setEnergyPoints(unsigned int value)
{
    energyPoints = value;
}

void ClapTrap::setAttackDamage(unsigned int value)
{
    attackDamage = value;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't attack because it has no hit points left." << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't attack because it has no energy points left." << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already out of hit points." << std::endl;
        return;
    }
    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage, remaining hit points: " << hitPoints << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't repair because it has no hit points left." << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't repair because it has no energy points left." << std::endl;
        return;
    }
    --energyPoints;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points, total hit points: " << hitPoints << "." << std::endl;
}
