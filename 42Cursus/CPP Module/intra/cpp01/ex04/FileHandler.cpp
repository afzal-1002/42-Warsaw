/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:25:08 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/18 17:18:02 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{
}

void FileHandler::copyData(const char *inputfile, std::string str1,
	std::string str2)
{
	char currentChar;
	size_t foundPos;
	std::string content;
	std::string filename;
	std::string outputFile;
	std::ifstream input;
	std::ofstream file;

	if (str1.empty())
	{
		std::cout << "Search string cannot be empty\n";
		return ;
	}

	filename = inputfile;
	if (filename.length() >= 4 && filename.substr(filename.length()
			- 4) == ".txt")
		filename = filename.substr(0, filename.length() - 4);

	outputFile = filename + ".replace";

	input.open(inputfile);
	if (input.fail())
	{
		std::cout << "Error while opening the file\n";
		return ;
	}

	file.open(outputFile.c_str());
	if (file.fail())
	{
		std::cout << "Error while creating the file\n";
		input.close();
		return ;
	}

	while (input.get(currentChar))
		content += currentChar;

	foundPos = 0;
	while ((foundPos = content.find(str1, foundPos)) != std::string::npos)
	{
		content.replace(foundPos, str1.length(), str2);
		foundPos += str2.length();
	}

	file << content;

	input.close();
	file.close();
}