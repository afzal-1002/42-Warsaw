/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/27 12:03:39 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;

    for (int i = 0; i < 4; i++)
        this->material[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "Material copy structor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (other.material[i])
            this->material[i] = other.material[i]->clone();
        else
            this->material[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "Material copy operator called" << std::endl;

    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->material[i])
                delete this->material[i];

            if (other.material[i])
                this->material[i] = other.material[i]->clone();
            else
                this->material[i] = NULL;
        }
    }

    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "Material destructor called" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (this->material[i])
            delete this->material[i];
    }
}

void MateriaSource::learnMateria(AMateria *material)
{
    if (!material)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (!this->material[i])
        {
            this->material[i] = material;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->material[i] && this->material[i]->getType() == type)
            return this->material[i]->clone();
    }
    return NULL;
}
