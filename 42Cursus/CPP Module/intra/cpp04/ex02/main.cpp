/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:59:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/07/26 13:03:13 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void testPolymorphism()
{	
	// const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
    cat->makeSound();

	delete dog;
	delete cat;
}

static void testStackObjects()
{
	Dog dog;
	Cat cat;

	std::cout << dog.getType() << " type on stack" << std::endl;
	std::cout << cat.getType() << " type on stack" << std::endl;
	dog.makeSound();
	cat.makeSound();
}

static void testDeepCopies()
{
	Dog originalDog;
	originalDog.setIdea(0, "chase the ball");
	Dog copiedDog(originalDog);
	copiedDog.setIdea(0, "guard the house");

	std::cout << "original dog idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copied dog idea: " << copiedDog.getIdea(0) << std::endl;

	Cat originalCat;
	originalCat.setIdea(0, "sleep on the keyboard");
	Cat copiedCat;
	copiedCat = originalCat;
	copiedCat.setIdea(0, "ignore everyone");

	std::cout << "original cat idea: " << originalCat.getIdea(0) << std::endl;
	std::cout << "copied cat idea: " << copiedCat.getIdea(0) << std::endl;
}

static void testAnimalArray()
{
	const int size = 6;
	Animal *animals[size];

	for (int i = 0; i < size; ++i)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < size; ++i)
	{
		std::cout << animals[i]->getType() << " in array" << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < size; ++i)
		delete animals[i];
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
	testDeepCopies();
	testAnimalArray();
	testWrongPolymorphism();
	return 0;
}
