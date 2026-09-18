/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:25:38 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/18 17:15:40 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
	HumanB(std::string name);
	~HumanB();
	void attack();

	void setWeapon(Weapon &weapon);
	Weapon *getWeapon(void);
};

#endif
