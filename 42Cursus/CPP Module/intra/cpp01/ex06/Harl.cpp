/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:38:29 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/18 17:22:55 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
				<< "You didn't put enough bacon in my burger! "
				<< "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
				<< "I've been coming for years, "
				<< "whereas you started working here "
				<< "just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! "
				<< "I want to speak to the manager now." << std::endl;
}

void Harl::complain(Level level)
{
	switch (level)
	{
	case DEBUG:
		std::cout << "[ DEBUG ]" << std::endl;
		debug();
		std::cout << std::endl;
	case INFO:
		std::cout << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl;
	case WARNING:
		std::cout << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl;
	case ERROR:
		std::cout << "[ ERROR ]" << std::endl;
		error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}