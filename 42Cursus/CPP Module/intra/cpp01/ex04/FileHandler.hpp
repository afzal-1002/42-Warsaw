/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:25:04 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/18 17:17:57 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

# include <fstream>
# include <iostream>
# include <string>

class FileHandler
{
  private:
  public:
	FileHandler();
	~FileHandler();

	void copyData(const char *inputfile, std::string str1, std::string str2);
};

#endif