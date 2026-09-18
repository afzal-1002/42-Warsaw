/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:25:18 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/18 17:14:31 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}
Weapon::Weapon(std::string type)
{
	this->type = type;
}
Weapon::~Weapon()
{
}
const std::string &Weapon::getType(void) const
{
	return (this->type);
}
void Weapon::setType(const std::string &type)
{
	this->type = type;
}
