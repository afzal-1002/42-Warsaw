/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/26 17:37:44 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria;

class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];
    Character();

public:
    Character(std::string const &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    virtual ~Character();

    virtual std::string const &getName() const;
    virtual void equip(AMateria *material);
    virtual void unequip(int indes);
    virtual void use(int index, ICharacter &target);
};

#endif
