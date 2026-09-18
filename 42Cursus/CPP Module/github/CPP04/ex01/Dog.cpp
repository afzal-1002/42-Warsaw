#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
        *this->brain = *other.brain;
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return this->brain->getIdea(index);
}
