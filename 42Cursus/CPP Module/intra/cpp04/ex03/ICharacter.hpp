/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/26 17:57:23 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
// #include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {}

    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *material) = 0;
    virtual void unequip(int index) = 0;
    virtual void use(int index, ICharacter &target) = 0;
};

#endif
