/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/26 18:14:23 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice Copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice assignment operator called" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// void Ice::use(ICharacter &target)
// {
//     std::cout << "* shoots an ice bolt at "
//               << target.getName()
//               << " *"
//               << std::endl;
// }
