/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:59:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/25 18:42:51 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void testPolymorphism()
{
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	
	
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();

	delete animal;
	delete dog;
	delete cat;
}

static void testStackObjects()
{
	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << animal.getType() << " type on stack" << std::endl;
	std::cout << dog.getType() << " type on stack" << std::endl;
	std::cout << cat.getType() << " type on stack" << std::endl;
	animal.makeSound();
	dog.makeSound();
	cat.makeSound();
}

static void testWrongPolymorphism()
{
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *wrong = new WrongCat();

	meta->makeSound();
	wrong->makeSound();

	delete meta;
	delete wrong;
}

int main()
{
	testPolymorphism();
	testStackObjects();
	testWrongPolymorphism();
	return 0;
}
