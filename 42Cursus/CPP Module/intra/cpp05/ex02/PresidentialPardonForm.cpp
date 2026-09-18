#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5), target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target): AForm("Presidential Pardon Form", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;

    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const
{
    return target;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}