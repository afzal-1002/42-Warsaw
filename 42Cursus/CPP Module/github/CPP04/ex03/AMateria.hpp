/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/26 15:31:20 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include  "ICharacter.hpp"

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const &type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();

    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target) = 0;
};

#endif
