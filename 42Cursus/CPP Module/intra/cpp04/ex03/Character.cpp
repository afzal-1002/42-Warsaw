/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/26 17:59:04 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const &name) : name(name)
{
	std::cout << "Character default constructor called" << std::endl;

    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character &other) : name(other.name)
{
	std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character Assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                delete this->inventory[i];
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called " << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *material)
{
    if (!material)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = material;
            return;
        }
    }
}

void Character::unequip(int index)
{
    if (index < 0 || index >= 4)
        return;
    this->inventory[index] = NULL;
}

void Character::use(int index, ICharacter &target)
{
    if (index < 0 || index >= 4)
        return;
    if (this->inventory[index]) 	
        this->inventory[index]->use(target);
}
