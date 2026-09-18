/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:08:28 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/18 16:55:26 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "Address of str:       " << &str << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of str:         " << str << std::endl;
	std::cout << "Value from stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value from stringREF: " << stringREF << std::endl;
	return (0);
}
