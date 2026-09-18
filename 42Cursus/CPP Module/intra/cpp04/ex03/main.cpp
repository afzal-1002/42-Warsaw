/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/26 15:28:58 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource *materialSource = new MateriaSource();

    materialSource->learnMateria(new Ice());
    materialSource->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    ICharacter *bob = new Character("Bob");

    AMateria *tmp;

    tmp = materialSource->createMateria("ice");
    me->equip(tmp);

    tmp = materialSource->createMateria("cure");
    me->equip(tmp);

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete materialSource;

    return 0;
}